// AVL-Self-Balancing Binary Tree - Dominykas V.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Dominykas Venskunas PRM AVL

#include<iostream>
#include <string>  // --> same #include<sstream>
using namespace std;
//------------------------------------Const
const string LINIJA = "==========================================";
//------------------------------------Main Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

}*root;
//------------------------------------Main Node Klase
class Tree{
public:
    int Aukstis(Node*);
    int Skirtumas(Node*);
    Node* rr_rotation(Node*);
    Node* ll_rotation(Node*);
    Node* lr_rotation(Node*);
    Node* rl_rotation(Node*);
    Node* Balansu(Node*);
    Node* Insert(Node*, int);
    void Display_Tree(Node*, int);
    void Is_Eiles(Node*);
    void Perdelioti(Node*);
    void postorder(Node*);
    void MedzioPasalinimas(Node*);
    int KiekElementu(Node*, int);
    bool NodePaieska(Node*, int);
//---
    bool MedzioTikrinimas(Node* Root, Node* &Prev) {
        if (Root) {
            if (!MedzioTikrinimas(Root->left, Prev)) {
                return false;
            }
            Prev = Root;
            return MedzioTikrinimas(Root->right, Prev);
        }
        return true;
    }
    bool ArBST(Node* Root) {
        Node* Prev = NULL;
        return MedzioTikrinimas(Root, Prev);
    }
 //---

    Tree(){
        root = NULL;
    }

};
//------------------------------------Voids
void Menu_Content(); //voidas po Main
//------------------------------------Ivedimu tikrinimas
double IrasytiNaujaSkaiciu() {

    string Skaicius;
    cin.clear();
    getline(cin, Skaicius);
    while (cin.fail() || cin.eof() || Skaicius.find_first_not_of("0123456789.") != string::npos) {
        cout << "Netinkamas formatas." << endl;
        cout << "Bandykite dar karta:> ";
        if (Skaicius.find_first_not_of("0123456789.") == string::npos) {
            cin.clear();
            cin.ignore(256, '\n');
        }
        getline(cin, Skaicius);
    }
    string::size_type st;
    return stod(Skaicius, &st);

}
//------------------------------------Tikrina ar medis tuscias
bool ArMedisTuscias(Node* tree) {

    if (tree == NULL) {
        cout << "Medis yra tuscias." << endl;
        cout << LINIJA << endl;
        return true;
    }
    return false;

}
//------------------------------------Main
int main(){

    int Kuri, Data;
    Tree Mazgas;
    while (true){
        Menu_Content();
        Kuri = IrasytiNaujaSkaiciu();
        cout << endl;
        switch (Kuri){
        case 1:
            cout << "==========Prideti nauja elementa==========" << endl;
            cout << "Koki elementa prideti:> ";
            Data = IrasytiNaujaSkaiciu();
            root = Mazgas.Insert(root, Data);
            break;
        case 2:
            cout << "========Pilnas Isbalansuotas medis========" << endl;
            if (ArMedisTuscias(root) == true) {
                continue;
            }
            Mazgas.Display_Tree(root, 1);
            cout << endl;
            cout << endl;
            break;
        case 3:
            cout << "========Vidinis apejimas (Inorder)========" << endl;
            if (ArMedisTuscias(root) == true) {
                continue;
            }
            cout << "Vidinis apejimas (Inorder):" << endl;
            Mazgas.Is_Eiles(root);
            cout << endl;
            break;
        case 4:
            cout << "======Tiesioginis apejimas (Preorder)=====" << endl;
            if (ArMedisTuscias(root) == true) {
                continue;
            }
            cout << "Tiesioginis apejimas (Preorder):" << endl;
            Mazgas.Perdelioti(root);
            cout << endl;
            break;
        case 5:
            cout << "=====Atvirkstinis apejimas (Postorder)====" << endl;
            if (ArMedisTuscias(root) == true) {
                continue;
            }
            cout << "Atvirkstinis apejimas (Postorder):" << endl;
            Mazgas.postorder(root);
            cout << endl;
            break;
        case 6:
            cout << "=========Pilnas medzio pasalinimas========" << endl;
            if (ArMedisTuscias(root) == true) {
                continue;
            }
            Mazgas.MedzioPasalinimas(root);
            root = NULL;
            cout << "Medis pasalintas." << endl;
            break; 
        case 7:
            cout << "=========Kiek yra elementu medyje=========" << endl;
            if (ArMedisTuscias(root) == true) {
                continue;
            }
            cout << "Elementu siame medyje yra: " << Mazgas.KiekElementu(root, 0) << "." << endl;
            break;
        case 8:
            cout << "===============Elemento paieska===============" << endl;
            if (ArMedisTuscias(root) == true) {
                continue;
            }
            cout << "Iveskite elemento kurio norite ieskoti:> ";
            Data = IrasytiNaujaSkaiciu();
            if (Mazgas.NodePaieska(root, Data) == true) {
                cout << "-- Elementas rastas --" << endl;
            }
            else {
                cout << "-- Elementas nerastas --" << endl;
            }
            break;
        case 9:
            cout << "======Ar medis tvarkingos strukturos======" << endl;
            if (ArMedisTuscias(root) == true) {
                continue;
            }
            if (Mazgas.ArBST(root)) {
                cout << "Medis tvarkingos strukturos." << endl;
            }
            else {
                cout << "Medis blogos strukturos." << endl;
            }
            break;
        case 10:
            cout << "==========================================" << endl;
            cout << "-=-=-=-=-=-=-=-=-E X I T=-=-=-=-=-=-=-=-=-" << endl;
            cout << "==========================================" << endl;
            exit(1);
            break;
        default:
            cout << "==========================================" << endl;
            cout << "         Tokio pasirinkimo nera." << endl;
        }
        cout << LINIJA << endl;
    }
    return 0;

}
//------------------------------------Menu
void Menu_Content() {

    cout << endl;
    cout << "|----------------------------------------|" << endl;
    cout << "|            Galimos komandos            |" << endl;
    cout << "|----------------------------------------|" << endl;
    cout << "|[1] - Prideti nauja elementa.           |" << endl;
    cout << "|[2] - Atspauzdinti pilna medi.          |" << endl;
    cout << "|[3] - Vidinis apejimas (Inorder).       |" << endl;
    cout << "|[4] - Tiesioginis apejimas (Preorder).  |" << endl;
    cout << "|[5] - Atvirkstinis apejimas (Postorder).|" << endl;
    cout << "|[6] - Pilnas medzio pasalinimas.        |" << endl;
    cout << "|[7] - Kiek yra elementu medyje.         |" << endl;
    cout << "|[8] - Elemento paieska.                 |" << endl;
    cout << "|[9] - Ar medis tvarkingos strukturos.   |" << endl;
    cout << "|[10] - Exit.                            |" << endl;
    cout << "|----------------------------------------|" << endl;
    cout << endl;
    cout << "Iveskite norima komanda:> ";

}
//------------------------------------Medzio aukstis // skirtumui
int Tree::Aukstis(Node* temp){

    int h = 0;
    if (temp != NULL){
        int l_Aukstis = Aukstis(temp->left);
        int r_Aukstis = Aukstis(temp->right);
        int max_Aukstis = max(l_Aukstis, r_Aukstis);
        h = max_Aukstis + 1;

    }
    return h;

}
//------------------------------------Aukscio balansavimas-skirtumas
int Tree::Skirtumas(Node* temp){

    int l_Aukstis = Aukstis(temp->left);
    int r_Aukstis = Aukstis(temp->right);
    int b_factor = l_Aukstis - r_Aukstis;
    return b_factor;

}
//------------------------------------Desines-Desinys sukimas
Node* Tree::rr_rotation(Node* parent){

    Node* temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;

}
//------------------------------------Kaires-Kairys sukimas
Node* Tree::ll_rotation(Node* parent){

    Node* temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;

}
//------------------------------------Kaires-Desinys sukimas
Node* Tree::lr_rotation(Node* parent){

    Node* temp;
    temp = parent->left;
    parent->left = rr_rotation(temp);
    return ll_rotation(parent);

}
//------------------------------------Desines-Kairys sukimas
Node* Tree::rl_rotation(Node* parent){

    Node* temp;
    temp = parent->right;
    parent->right = ll_rotation(temp);
    return rr_rotation(parent);

}
//------------------------------------Balansavimas
Node* Tree::Balansu(Node* temp){

    int bal_factor = Skirtumas(temp);
    if (bal_factor > 1) {
        if (Skirtumas(temp->left) > 0) {
            temp = ll_rotation(temp);
        }       
        else {
            temp = lr_rotation(temp);
        }       
    }
    else if (bal_factor < -1){
        if (Skirtumas(temp->right) > 0)
            temp = rl_rotation(temp);
        else {
            temp = rr_rotation(temp);
        }
    }
    return temp;

}
//------------------------------------Prideti Elementa
Node* Tree::Insert(Node* root, int value){

    if (root == NULL){
        root = new Node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
   /* else if (value == root->data) {                       //Jei elementas jau yra jo nebedeti i TREE
      cout << "Deje toks elementas jau yra." << endl;       //
      return root;                                          //
   }*/                                                      //
    else if (value < root->data){
        root->left = Insert(root->left, value);
        root = Balansu(root);
    }
    else if (value >= root->data){
        root->right = Insert(root->right, value);
        root = Balansu(root);
    }
    return root;

}
//------------------------------------Atvaizduoti Medi
void Tree::Display_Tree(Node* ptr, int level){

    if (ptr != NULL){
        Display_Tree(ptr->right, level + 1);
        cout << endl;
        if (ptr == root) {
            cout << "Root -> ";
        }  
        for (int i = 0; i < level && ptr != root; i++) {
            cout << "        ";
        }    
        cout << ptr->data;
        Display_Tree(ptr->left, level + 1);
    }
    
}
//------------------------------------Vidinis apejimas (Inorder)
void Tree::Is_Eiles(Node* tree){

    if (tree == NULL) {
        return;
    }
    Is_Eiles(tree->left);
    cout << tree->data << "  ";
    Is_Eiles(tree->right);

}
//------------------------------------Tiesioginis apejimas (Preorder)
void Tree::Perdelioti(Node* tree){

    if (tree == NULL) {
        return;
    }    
    cout << tree->data << "  ";
    Perdelioti(tree->left);
    Perdelioti(tree->right);

}
//------------------------------------Atvirkstinis apejimas (Postorder)
void Tree::postorder(Node* tree){

    if (tree == NULL) {
        return;
    }
    postorder(tree->left);
    postorder(tree->right);
    cout << tree->data << "  ";

}
//------------------------------------ Pasalina Visa Medi
void Tree::MedzioPasalinimas(Node* tree) {

    if (tree == NULL) {
        return;
    }
    MedzioPasalinimas(tree->left);
    MedzioPasalinimas(tree->right);
    delete tree;

}
//------------------------------------ Kiek Nariu Yra Medyje
int Tree::KiekElementu(Node* tree, int Kiek) {

    if (tree == NULL) {
        return 0;
    }   
    if (Kiek == 0) {
        Kiek++;
    }
    if (tree->left != NULL) {
        Kiek++;
        Kiek = KiekElementu(tree->left, Kiek);
    }     
    if(tree->right != NULL) {
        Kiek++;    
        Kiek = KiekElementu(tree->right, Kiek);
    } 
    return Kiek;

}
//------------------------------------Nario Paieska
bool Tree::NodePaieska(Node* tree, int Raktas) {

    bool ArRado = false;
    if (tree == NULL) {
        return false;
    }
    if (tree->left != NULL) {
        ArRado = NodePaieska(tree->left, Raktas);
        if (ArRado == true) return true;
    }
    if (tree->right != NULL) {
        ArRado = NodePaieska(tree->right, Raktas); 
        if (ArRado == true) return true;               
    }
    if (tree->data == Raktas || ArRado == true) {
        return true;
    }
    return false;

}
//-------------------------------


