#include <iostream>
using namespace std;
//change the code to demonstrate different types of access specifiers in inheritance    
// Demonstrate how public / protected / private inheritance affect access

class Parent {
public:
    string name;          // public: accessible everywhere
protected:
    int age;              // protected: accessible in derived classes
private:
    int id;               // private: accessible only inside Parent

public:
    Parent(const string &n, int a, int i) : name(n), age(a), id(i) {
        cout << "Parent Constructor Called\n";
    }

    void showPublic() const {
        cout << "Parent::showPublic -> name=" << name << "\n";
    }

    int getId() const { return id; } // accessor for private member

    ~Parent() {
        cout << "Parent Destructor Called\n";
    }
};

// Public inheritance: public/protected members keep their access in the derived class
class PublicDerived : public Parent {
public:
    PublicDerived(const string &n, int a, int i) : Parent(n, a, i) {
        cout << "PublicDerived Constructor Called\n";
    }

    void access() {
        cout << "PublicDerived::access -> can see public: " << name << "\n";
        cout << "PublicDerived::access -> can see protected: " << age << "\n";
        cout << "PublicDerived::access -> cannot access private id directly, but can via getter: " << getId() << "\n";
    }
};

// Protected inheritance: public and protected members of Parent become protected in Derived
class ProtectedDerived : protected Parent {
public:
    ProtectedDerived(const string &n, int a, int i) : Parent(n, a, i) {
        cout << "ProtectedDerived Constructor Called\n";
    }

    void access() {
        cout << "ProtectedDerived::access -> can see (now protected) name: " << name << "\n";
        cout << "ProtectedDerived::access -> can see protected age: " << age << "\n";
    }
};

// Private inheritance: public and protected members of Parent become private in Derived
class PrivateDerived : private Parent {
public:
    PrivateDerived(const string &n, int a, int i) : Parent(n, a, i) {
        cout << "PrivateDerived Constructor Called\n";
    }

    void access() {
        cout << "PrivateDerived::access -> can see (now private) name: " << name << "\n";
        cout << "PrivateDerived::access -> can see (now private) age: " << age << "\n";
    }
};

// A class derived from PublicDerived: it can access protected members inherited from Parent
class SubFromPublic : public PublicDerived {
public:
    SubFromPublic(const string &n, int a, int i) : PublicDerived(n, a, i) {}
    void accessSub() {
        cout << "SubFromPublic::accessSub -> can access protected 'age' from Parent: " << age << "\n";
    }
};

// A class derived from PrivateDerived: it CANNOT access Parent's members (they became private in PrivateDerived)
class SubFromPrivate : public PrivateDerived {
public:
    SubFromPrivate(const string &n, int a, int i) : PrivateDerived(n, a, i) {}
    void accessSub() {
        cout << "SubFromPrivate::accessSub -> cannot access Parent's members here (they are private in PrivateDerived)\n";
    }
};

int main() {
    cout << "-- Demonstrating access with different inheritance specifiers --\n";

    Parent p("ParentName", 50, 1001);
    p.showPublic();
    cout << "From main: can access public member 'name': " << p.name << "\n";
    // cout << p.age; // error: 'age' is protected in Parent

    cout << "\n-- Public inheritance --\n";
    PublicDerived pub("PubDerived", 40, 2002);
    pub.access();
    cout << "From main: public member 'name' is still public through PublicDerived: " << pub.name << "\n";

    cout << "\n-- Protected inheritance --\n";
    ProtectedDerived prot("ProtDerived", 35, 3003);
    prot.access();
    // From main, prot.name is NOT accessible because it became protected in ProtectedDerived
    // cout << prot.name; // compile error if uncommented

    cout << "\n-- Private inheritance --\n";
    PrivateDerived priv("PrivDerived", 30, 4004);
    priv.access();
    // From main, priv.name is NOT accessible because it became private in PrivateDerived
    // cout << priv.name; // compile error if uncommented

    cout << "\n-- Derived-from-derived differences --\n";
    SubFromPublic sp("SubPub", 25, 5005);
    sp.accessSub();

    SubFromPrivate sip("SubPriv", 20, 6006);
    sip.accessSub();

    return 0;
}