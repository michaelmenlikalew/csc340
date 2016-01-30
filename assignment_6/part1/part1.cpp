#include <iostream>
#include <exception>

using namespace std;
/*
 * Exception_ID_Not_Found - exception inheritance
 *
 * throw "ID not found!";
 */
class Exception_ID_Not_Found : public exception {
public:
    const char* what() const throw() {
        return "ID not found!";
    }
} id_not_found;

int getProductID(int ids[], string names[], int numProducts, string target)
{
    for (int i = 0; i < numProducts; i++)
    {
        if (names[i] == target)
            return ids[i];
    }
    throw id_not_found;
}

int main()
{
    int productIds[] = {4, 5, 8, 10, 13};
    string products[] = { "computer", "flash drive", "mouse", "printer",
                          "camera" };

    try {
        cout << getProductID(productIds, products, 5, "mouse") << endl;
    } catch (Exception_ID_Not_Found& excp) {
        cout << excp.what() << endl;
    }
    try {
        cout << getProductID(productIds, products, 5, "printer") << endl;
    } catch (Exception_ID_Not_Found& excp) {
        cout << excp.what() << endl;
    }
    try {
        cout << getProductID(productIds, products, 5, "laptop") << endl;
    } catch (Exception_ID_Not_Found& excp) {
        cout << excp.what() << endl;
    }
    
    return 0;
}
