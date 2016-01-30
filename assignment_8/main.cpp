/* Shwe Aye
 * 915827905
 * saye@mail.sfsu.edu
 * Assignment 8
 * Nov. 30, 2015
 * I used g++ compiler on Linux(GNU)/Unix.
 */

#include "graph.h"
using namespace std;

int main()
{
    Graph<string> g;
    Node<string>* a = g.insert("a");
    Node<string>* b = g.insert("b");
    Node<string>* c = g.insert("c");
    Node<string>* d = g.insert("d");
    Node<string>* e = g.insert("e");
    g.connect(a, b);
    g.connect(c, d);
    g.connect(b, e);
    g.connect(c, e);
    cout << "Graph 1" << endl;
    g.print();
    cout << "-----" << endl;

    vector<Node<string>*> path = g.shortestPath("a", "e");
    cout << "Graph 1: path from a to e: ";
    for (unsigned int i = 0; i < path.size(); i++) {
        cout << path[i]->value << " ";
    }
    cout << endl;
    cout << "----" << endl;

    Graph<string> g2(g);
    g2.connect("a", "e");
    cout << "Graph 1 again" << endl;
    g.print();
    cout << "-----" << endl;
    cout << "Graph 2" << endl;
    g2.print();
    cout << "-----" << endl;

    path = g.shortestPath("a", "e");
    cout << "Graph 1: path from a to e: ";
    for (unsigned int i = 0; i < path.size(); i++) {
        cout << path[i]->value << " ";
    }
    cout << endl;
    cout << "----" << endl;

    path = g2.shortestPath("a", "e");
    cout << "Graph 2: path from a to e: ";
    for (unsigned int i = 0; i < path.size(); i++) {
        cout << path[i]->value << " ";
    }
    cout << endl;
    cout << "----" << endl;

    Graph<string> g3;
    g3.insert("z");         // this should get overwritten
    g3.insert("y");         // and this
    g3.connect("y", "z");   // also this
    g3 = g;
    g3.connect("a", "e");
    cout << "Graph 1 a third time" << endl;
    g.print();
    cout << "-----" << endl;
    cout << "Graph 3" << endl;
    g3.print();
    cout << "-----" << endl;

    path = g.shortestPath("a", "e");
    cout << "Graph 1: path from a to e: ";
    for (unsigned int i = 0; i < path.size(); i++) {
        cout << path[i]->value << " ";
    }
    cout << endl;
    cout << "----" << endl;

    path = g3.shortestPath("a", "e");
    cout << "Graph 3: path from a to e: ";
    for (unsigned int i = 0; i < path.size(); i++) {
        cout << path[i]->value << " ";
    }
    cout << endl;
    cout << "----" << endl;

    bool err = false;
    Graph<string> g4(g);
    g4.insert("z");
    g4.insert("y");
    g4.connect("y", "z");
    cout << "-----" << endl;
    cout << "Graph 4" << endl;
    g4.print();
    cout << "-----" << endl;
    try {
        path = g4.shortestPath("a", "y");
    } catch (exception &e) {
        cout << "Graph 4: path from a to y: ";
        cout << e.what();
        err = true;
    }
    if (!err) {
        cout << "Graph 4: path from a to y: ";
        for (unsigned int i = 0; i < path.size(); i++) {
            cout << path[i]->value << " ";
        }
    }
    cout << endl;
    cout << "----" << endl;

    Graph<string> g5(g4);
    g5.insert("z");
    g5.insert("f");
    g5.insert("g");
    g5.insert("h");
    g5.insert("i");
    g5.insert("j");
    g5.insert("k");
    g5.insert("l");
    g5.connect("y", "z");
    g5.connect("e", "f");
    g5.connect("f", "g");
    g5.connect("h", "g");
    g5.connect("i", "h");
    g5.connect("i", "j");
    g5.connect("k", "j");
    g5.connect("k", "l");
    g5.connect("y", "l");

    cout << "-----" << endl;
    cout << "Graph 5" << endl;
    g5.print();
    cout << "-----" << endl;
    path = g5.shortestPath("a", "l");
    cout << "Graph 5: path from a to l: ";
    for (unsigned int i = 0; i < path.size(); i++) {
        cout << path[i]->value << " ";
    }
    cout << endl;

    return 0;
}

