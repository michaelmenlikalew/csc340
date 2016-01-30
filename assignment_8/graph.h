/* Shwe Aye
 * 915827905
 * saye@mail.sfsu.edu
 * Assignment 8
 * Nov. 30, 2015
 * I used g++ compiler on Linux(GNU)/Unix.
 */

#ifndef _GRAPH_H
#define _GRAPH_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#include <stdexcept>

/*
 * Exception for trying to find
 * a path between two nodes if
 * at least one of the nodes
 * doesn't exist.
 */
class NonExistentNodeException : public std::exception
{
public:
    virtual const char* what() const throw() {
        return "At least one of those nodes doesn't exist!";
    }
};

/*
 * Exception for trying to find
 * a path between two nodes when
 * no path exists.
 */
class NoPathException : public std::exception
{
public:
    virtual const char* what() const throw() {
        return "No path exists between those two nodes!";
    }
};

/*
 * Node
 * -----
 * Represents a node in a graph. T is
 * the type of value held in the node.
 */
template <typename T>
class Node
{
public:
    Node() : marked(false) {}
    Node(const T& value) : value(value), marked(false) {}

    /*
     * Why wouldn't this do what we want?
     *
     * Hint: what is the new node connected to?
     */
    Node<T>* copy(const Node& other) {
        if (!this)
            this->adjacent.clear();
        this->value = other.value;
        this->adjacent = other.adjacent;
        return this;
    }

    ~Node() {
        this->value = -1;
        marked = false;
    }

    /*
     * Why not a vector for the list of adjacent
     * nodes?
     */
    std::unordered_set<Node<T>*> adjacents;
    T value;
    bool marked;
};

/*
 * Graph
 * -----
 * Represents a bi-directional (undirected)
 * graph. Nodes can have any value. The
 * graph does not have to be connected. Values
 * must be unique.
 */
template <typename T>
class Graph
{
public:
    Graph() {}

    /*
     * Since we dynamically allocate each node,
     * we need the big 3!
     *
     * - destructor
     * - copy constructor
     * - assignment operator
     */
    ~Graph() {
        clear();
    }

    Graph(const Graph<T>& other) {
        copyOther(other);
    }

    Graph<T>& operator=(const Graph<T>& other) {
        if (this != &other) {
            clear();
            copyOther(other);
        }
        return *this;
    }

    /*
     * Common graph operations.
     */
    Node<T>* insert(const T& value) {
        if (nodes.find(value) != nodes.end()) {
            return NULL;
        }

        Node<T>* newNode = new Node<T>(value);
        nodes[value] = newNode;
        return newNode;
    }

    // Two versions of connect! One that takes
    // node pointers, another that takes node
    // values.
    void connect(Node<T>* first, Node<T>* second) {
        first->adjacents.insert(second);
        second->adjacents.insert(first);
    }

    void connect(const T& first, const T& second) {
        if (nodes.find(first) == nodes.end() ||
            nodes.find(second) == nodes.end()) {
            throw NonExistentNodeException();
        }

        connect(nodes[first], nodes[second]);
    }

    void unmarkAll() {
        for (auto iter = nodes.begin();
             iter != nodes.end();
             iter++) {
            iter->second->marked = false;
        }
    }

    void print() {
        for (auto iter = nodes.begin();
             iter != nodes.end();
             iter++) {
            std::cout << iter->first << ": ";

            for (auto neighborsIter = iter->second->adjacents.begin();
                 neighborsIter != iter->second->adjacents.end();
                 neighborsIter++) {

                std::cout << (*neighborsIter)->value << " ";
            }
            std::cout << std::endl;
        }
    }

    std::vector<Node<T>*> shortestPath(const T& start, const T& end);
        // make sure both nodes exist! If one doesn't, throw
        // the appropriate exception.


        // Ok, both nodes exist. Get the node pointers from
        // your unordered_map!


        // You will need some way to store partial paths.
        // I highly recommend representing a partial
        // path as a vector of node pointers, since this
        // is what you will ultimately be returning.
        //
        // I would ALSO recommend using a deque to store
        // all your partial pathstd::cout << "\n3: " << tmp->value << std::endl;s. (A deque is
        // shorthand for double-ended queue. It's part
        // of the STL.
        //
        // If you choose to use a deque (which you should),
        // you'll have a deque of vectors, where each vector
        // in turn contains node pointers. Kind of
        // complicated! But effective!


        // Don't forget to unmark your nodes!


        // Your first partial path will just contain one
        // node - the start node. Not much of a path, but
        // you have to start somewhere!


        // Now, repeatedly do the following:
        //    1. Get the topmost partial path.
        //    2. Look at every node you can get to from
        //       the end of that partial path (ignoring
        //       nodes you've already seen).
        //    3. Create a partial path that has the same
        //       nodes as the current partial path, PLUS
        //       one more node (the node that you're
        //       looking at).
        //    4. Store those partial paths at the end.
        //
        // You stop when:
        //    - You see the end node in step 2. Put the
        //      end node at the end of the current partial
        //      path, and then return the partial (now
        //      complete) path!
        //    - You run out of partial paths to look at.
        //      If this ever happens, that means there is
        //      no path to the end node. Throw the
        //      appropriate exception.


        // This method returns an empty vector for now.
        // Get rid of this line!

private:
    std::unordered_map<T, Node<T>*> nodes;  // for uniqueness and lookup

    void copyOther(const Graph<T>& other) {
        for (auto iter = other.nodes.begin();
             iter != other.nodes.end();
             iter++) {
            insert(iter->first);
        }

        for (auto iter = other.nodes.begin();
             iter != other.nodes.end();
             iter++) {
            auto adjacents = iter->second->adjacents;
            for (auto neighborsIter = adjacents.begin();
                 neighborsIter != adjacents.end();
                 ++neighborsIter) {
                // Need to connect the values here!
                // Connecting iter->second and *neighborsIter
                // would re-connect the nodes in the old graph
                // (so this would do nothing)
                connect(iter->first, (*neighborsIter)->value);
            }
        }
    }

    void clear() {
        for (auto iter = nodes.begin();
             iter != nodes.end();
             iter++) {
            delete iter->second;
        }

        nodes.clear();
    }
};

/*
 * is_shortestPath - helper function for shortestPath
 *
 * see shortestPath for the main
 */
template <typename A, typename B, typename C, typename T>
bool is_shortest_Path(A &nodes, B &list, C &crn_vt, C &nx_vt, const T &end )
{
    Node<T> *x = nodes.at(crn_vt.back()->value);
    auto adj = x->adjacents;
    for (auto n_itr = adj.begin(); n_itr != adj.end(); n_itr++) {
        if ((*n_itr)->marked == false) {
            (*n_itr)->marked = true;
            nx_vt = crn_vt;
            auto rho = (*n_itr)->value;
            nx_vt.push_back(new Node<T>(rho));
            list.push(nx_vt);
            if (rho == end)
                return true;
        }
    }
    return false;
}

/*
 * shortestPath - find the shortestpath between the node start and end
 * @crn_vt: current vector
 * @nx_vt: next vector
 * @list: list of vector of nodes
 * 
 * not using deque, don't see the reason to use it here
 * if the two nodes doesn't exist, throw excepiton
 * put a node at crn_vt, then push that vector to list
 * start a loop, if list isn't empty get the top of the queue, then pop it.
 * if the list is empty, there are no path to the edges, throw an exception
 * iterate the map and find the next neighbor node, if not marked, mark it
 * push_back that value into the nx_vt and if that value is same with end value,
 * return that vector, if not, push nx_vt to the queue
 * helper function code are also commented here
 */
template<typename T>
std::vector<Node<T>*> Graph<T>::shortestPath(const T& start, const T& end)
{
    if (nodes.find(start) == nodes.end() || nodes.find(end) == nodes.end()) {
        throw NonExistentNodeException();
    }
    std::queue< std::vector <Node<T> *> > list;
    std::vector<Node<T> *> crn_vt, nx_vt;
    crn_vt.push_back(new Node<T>(nodes.at(start)->value));
    list.push(crn_vt);
    unmarkAll();
    do {
        if (!list.empty()) {
            crn_vt = list.front();
            list.pop();
        } else {
            throw NoPathException();
        }
        if (is_shortest_Path(nodes, list, crn_vt, nx_vt, end))
            return nx_vt;
    } while (true);

    return nx_vt;
}

#endif
