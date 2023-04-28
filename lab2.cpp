
#include "zadanie1.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

void zadanie1() {
    cout << "Podaj liczbe sekund: ";
    unsigned int sec = 0;
    cin >> sec;
    TimeSpan ts1(sec);
    ts1.print();
}

class Student {
public:
    unsigned int indeks;
    string imie;
    string nazwisko;
    Student(unsigned int indeks, string imie, string nazwisko);
    void print();
    unsigned int getIndeks();
    string getImie();
    string getNazwisko();
};
Student::Student(unsigned int indeks, string imie, string nazwisko) {
    this->indeks = indeks;
    this->imie = imie;
    this->nazwisko = nazwisko;
}
void Student::print() {
    cout << "Indeks: " <<
        this->indeks << ", imie: " <<
        this->imie << ", nazwisko: " <<
        this->nazwisko << endl;
}

unsigned int Student::getIndeks() {
    return this->indeks;
}
string Student::getImie() {
    return this->imie;
}
string Student::getNazwisko() {
    return this->nazwisko;
}
class BazaStudentow
{
public:
    vector<Student> bazaStudentow;
    void add(unsigned int index, string imie, string nazwisko);
    void print();
    void search(unsigned int index);
    bool deleteS(unsigned int index);
    void save();
    void read();
    void deleteDatabase();
};
void BazaStudentow::add(unsigned int index, string imie, string nazwisko) {
    this->bazaStudentow.push_back(Student(index, imie, nazwisko));
}
void BazaStudentow::print() {
    for (Student& s : bazaStudentow) {
        s.Student::print();
    }
}
void BazaStudentow::search(unsigned int index) {
    for (Student& s : bazaStudentow) {
        if (s.getIndeks() == index) {
            s.Student::print();
            return;
        }
    }
}
bool BazaStudentow::deleteS(unsigned int index) {
    int i = -1;
    for (Student& s : bazaStudentow) {
        i++;
        if (s.getIndeks() == index) {
            bazaStudentow.erase(bazaStudentow.begin() + i);
            return true;
        }
    }
    return false;
}
void BazaStudentow::deleteDatabase() {
    bazaStudentow.clear();
}
void BazaStudentow::save() {
    ofstream myfile;
    myfile.open("bazaStudentow.txt");
    for (Student& s : bazaStudentow) {
        myfile << s.getIndeks() << " " <<
            s.getImie() << " " <<
            s.getNazwisko() << endl;
    }
    myfile.close();
}
void BazaStudentow::read() {
    ifstream file("bazaStudentow.txt");
    string str;
    while (std::getline(file, str)) {
        cout << str << endl;
    }
}

void zadanie2() {
    BazaStudentow  st ;
    int ile;
    cout << "Liczba studentow";
        cin >> ile;
        unsigned int index;
            string imie;
            string nazwisko;
        for (int i = 0; i < ile; i++) {
            cout << "Podaj index: ";
            cin >> index;
            cout << "Podaj imie: ";
            cin >> imie;
            cout << "Podaj nazwisko: ";
            cin >> nazwisko;
            st.add(index,imie,nazwisko);
        }
        st.print();
        cout << "Podaj index szukanego studenta: ";
        cin >> index;
        st.search(index);
        cout << "Podaj index usuwanego studenta: ";
        cin >> index;
        st.deleteS(index);
            st.save();
            st.read();
            st.deleteDatabase();
}


template <class T>
class Node {
public:
    T valueInTree;
    Node* left;
    Node* right;
    int level;
    Node(T value) : valueInTree(value), left(nullptr), right(nullptr) {}
    Node() {
        left = nullptr;
        right = nullptr;
        valueInTree = 0;
        level = 0;
    }

};

template <class T>
class Tree {
public:
    Node<T>* root;

    Tree() {
        root = nullptr;
    }

    void insert(T valueToAdd) {
        root = insert(valueToAdd, root);
    }

    Node<T>* insert(T valueToAdd, Node<T>* treeNode) {
        if (treeNode == nullptr) {
            treeNode = new Node<T>;
            treeNode->valueInTree = valueToAdd;
            treeNode->left = nullptr;
            treeNode->right = nullptr;
        }
        else if (valueToAdd < treeNode->valueInTree)  treeNode->left = insert(valueToAdd, treeNode->left);
        else if (valueToAdd > treeNode->valueInTree)  treeNode->right = insert(valueToAdd, treeNode->right);


        return treeNode;
    }

    void remove(T valueToRemove) {
        root = remove(valueToRemove, root);
    }
    Node<T>* remove(T valueToRemove, Node<T>* treeElement) {
        Node<T>* temp;
        if (treeElement == NULL)
            return NULL;
        else if (valueToRemove < treeElement->valueInTree)
            treeElement->left = remove(valueToRemove, treeElement->left);
        else if (valueToRemove > treeElement->valueInTree)
            treeElement->right = remove(valueToRemove, treeElement->right);
        else if (treeElement->left && treeElement->right)
        {
            temp = findMin(treeElement->right);
            treeElement->valueInTree = temp->valueInTree;
            treeElement->right = remove(treeElement->valueInTree, treeElement->right);
        }
        else
        {
            temp = treeElement;
            if (treeElement->left == NULL)
                treeElement = treeElement->right;
            else if (treeElement->right == NULL)
                treeElement = treeElement->left;
            delete temp;
        }

        return treeElement;
    }

    void printInOrder() { inOrder(root); }

    void inOrder(Node<T>* treeNode) {
        if (!treeNode) return;
        inOrder(treeNode->left);
        cout << treeNode->valueInTree << " ";
        inOrder(treeNode->right);

    }
    bool contains(int data) {
        return contains(root, data);
    }
    bool contains(Node<T>* top, int data) {
        if (top == nullptr) return false;
        else {
            if (data == top->valueInTree)
                return true;
            else if (data < top->valueInTree)
                return contains(top->left, data);
            else if (data > top->valueInTree)
                return contains(top->right, data);
        }
    }

    void clear() {
        leafDelete(root);
    }

    Node<T>* leafDelete(Node<T>* root) {
        if (root == NULL)
            return NULL;
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        root->left = leafDelete(root->left);
        root->right = leafDelete(root->right);

        return root;
    }

    int numberOfElements(Node<T>* root) {
        if (root) return 1 + numberOfElements(root->left) + numberOfElements(root->right);
        else return 0;
    }

    bool isEmpty() {
        int howManyElements = numberOfElements(root);
        if (howManyElements == 0) return true;
        else return false;
    }
};
void zadanie3() {
    Tree <int> bst;
    cout << (bst.isEmpty() ? "Drzewo jest puste" : "Drzewo nie jest puste") << endl;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(4);
    bst.insert(2);
    cout << (bst.isEmpty() ? "Drzewo jest puste" : "Drzewo nie jest puste") << endl;
    cout << "Drzewo zawiera element o wartosci 3: " << bst.contains(3) << endl;
    cout << "Drzewo zawiera element o wartosci 9: " << bst.contains(9) << endl;
    bst.printInOrder();
    cout << endl;
    bst.clear();
    cout << (bst.isEmpty() ? "Drzewo jest puste" : "Drzewo nie jest puste") << endl;
}


struct Element
{
    char cyfra;
    int licznik;
    Element* nast;
} *poc = NULL, * okr;

bool ulamek_okresowy(int x)
{
    for (okr = poc; okr != NULL && okr->licznik != x; okr = okr->nast)
        ;
    return okr != NULL;
}

void rozwin_ulamek(int x, int y)
{
    Element* p, * kon = NULL;
    for (; x != 0 && !ulamek_okresowy(x); x %= y)
    {
        (p = new Element)->licznik = x;
        p->cyfra = (x *= 10) / y;
        if (kon != NULL)
            kon->nast = p;
        else
            poc = p;
        (kon = p)->nast = NULL;
    }
}

void drukuj_ulamek(int x, int y)
{
    cout << "Rozwiniecie: ";
    if (x * y < 0) cout << "-";
    cout << abs(x / y);
    if (poc == NULL) return;
    cout << ".";
    for (Element* p = poc; p != NULL; p = p->nast)
    {
        if (p == okr) cout << "(";
        cout << int(p->cyfra);
    }
    if (okr != NULL) cout << ")";
}

void usun_liste()
{
    Element* p;
    while (poc != NULL)
    {
        poc = (p = poc)->nast;
        delete p;
    }
}

bool czytaj_dane(int& p, int& q)
{
    cout << "Licznik: ";
    if (!(cin >> p)) return false;
    cin.ignore(1000, '\n');
    cout << "Mianownik: ";
    return ((cin >> q) && q != 0);
}
void zadanie4() {
    int x, y;
    cout << "Rozwiniecie dziesietne ulamka\n"
        "-----------------------------\n";
    if (!czytaj_dane(x, y))
    {
        cout << "Problem z danymi.\n";
        
    }
    rozwin_ulamek(abs(x % y), abs(y));
    drukuj_ulamek(x, y);
    cout << endl;
    usun_liste();


}

class Doskonala
{
    bool czy_podzielnik(int p, int l) {
        return p % l;
    }

    bool czy_doskonala(long long int n)
    {
        long long int sum = 1;
        for (long long int i = 2; i * i <= n; i++) {
            if (n % i == 0)
            {
                if (i * i != n)
                    sum = sum + i + n / i;
                else
                    sum = sum + i;
            }
        }

        if (sum == n && n != 1)
            return true;

        return false;
    }

public:
    int pierwsza_dosk() {
        for (int n = 2; n < 10000; n++)
            if (czy_doskonala(n))
            {
                cout << n << " jest pierwsza liczba doskonala \n";
                return n;
            }
    }

};
bool czy_doskonala(long long int n)
{
    long long int sum = 1;
    for (long long int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i != n)
                sum = sum + i + n / i;
            else
                sum = sum + i;
        }
    }

    if (sum == n && n != 1)
        return true;

    return false;
}

bool czy_podzielnik(int p, int l) {
    return p % l;
}

int pierwsza_dosk() {
    for (int n = 2; n < 10000; n++)
        if (czy_doskonala(n)) {
            cout << n << " jest pierwsza liczba doskonala \n";
            return n;
        }
}

void zadanie5() {
    cout << "Ktora liczbe doskonala z kolei chcesz znalezc: ";
    int liczba;
    cin >> liczba;

    int ile = 0;
    int i = 0;
    while (true) {
        if (czy_doskonala(i)) {
            ile++;
            if (ile == liczba) {
                cout << i << endl;
                return;
            }
        }
        i++;
    }
}
int main()
{
    int zadanie = 0;
    do {
        cout << endl;
        cout << "Lista zadan" << endl;
        cout << "1) Zadanie pierwsze" << endl;
        cout << "2) Zadanie drugie" << endl;
        cout << "3) Zadanie trzecie" << endl;
        cout << "4) Zadanie czwarte" << endl;
        cout << "5) Zadanie piate" << endl;
        cout << "6) Wyjscie" << endl;

        cout << "Prosze podac numer zadania: ";
        cin >> zadanie;
        cout << endl;
        switch (zadanie) {
        case 1:
            cout << "ZADANIE PIERWSZE" << endl;
            cout << "=========================================" << endl;
            zadanie1();
            break;

        case 2:
            cout << endl << "ZADANIE DRUGIE" << endl;
            cout << "=========================================" << endl;
            zadanie2();
            break;

        case 3:
            cout << endl << "ZADANIE TRZECIE" << endl;
            cout << "=========================================" << endl;
            zadanie3();
            break;

        case 4:
            cout << endl << "ZADANIE CZWARTE" << endl;
            cout << "=========================================" << endl;
            zadanie4();
            break;

        case 5:
            cout << endl << "ZADANIE PIATE" << endl;
            cout << "=========================================" << endl;
            zadanie5();
            break;

        case 6: break;
        default: cout << "Nie ma takiej opcji do wyboru!" << endl;
        }
    } while (zadanie != 6);

    return 0;
}

