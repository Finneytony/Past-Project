#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    string name;
    vector<TreeNode*> children;
    int size;

    TreeNode(string name, int size) : name(name), size(size) {}
};

int diskSpace(const TreeNode& T, const TreeNode& p) {
    int s = p.size; // start with size of p

    if (!p.children.empty()) { // if p is internal
        for (const TreeNode* child : p.children) {
            s += diskSpace(T, *child); // sum the space of subtrees
        }
    }

    cout << p.name << ": " << s << " bytes" << endl; // print summary

    return s;
}

int main() {
    // Example directory structure
  cout<<"\nBelow are the values of Each Nodes\n";
  cout<<"-----------------------------------------\n";
    TreeNode* root = new TreeNode("/user/rt/courses/", 1024);
    TreeNode* cs016 = new TreeNode("cs016", 2048);
    TreeNode* grades = new TreeNode("grades", 8192);
    TreeNode* homeworks = new TreeNode("homeworks", 1024);
    TreeNode* programs = new TreeNode("programs", 1024);
    TreeNode* hw1 = new TreeNode("hw1", 3072);
    TreeNode* hw2 = new TreeNode("hw2", 2048);
    TreeNode* hw3 = new TreeNode("hw3", 4096);
    TreeNode* pr1 = new TreeNode("pr1", 58368);
    TreeNode* pr2 = new TreeNode("pr2", 99328);
    TreeNode* pr3 = new TreeNode("pr3", 75776);
    TreeNode* cs252 = new TreeNode("cs252", 1024);
    TreeNode* projects = new TreeNode("projects", 1024);
    TreeNode* grades2 = new TreeNode("grades", 3072);
    TreeNode* papers = new TreeNode("papers", 1024);
    TreeNode* demos = new TreeNode("demos", 1024);
    TreeNode* buylow = new TreeNode("buylow", 26624);
    TreeNode* sellhigh = new TreeNode("sellhigh", 56320);
    TreeNode* market = new TreeNode("market", 4898816);

    root->children.push_back(cs016);
    root->children.push_back(cs252);
    cs016->children.push_back(grades);
    cs016->children.push_back(homeworks);
    cs016->children.push_back(programs);
    homeworks->children.push_back(hw1);
    homeworks->children.push_back(hw2);
    homeworks->children.push_back(hw3);
    programs->children.push_back(pr1);
    programs->children.push_back(pr2);
    programs->children.push_back(pr3);
    cs252->children.push_back(grades2);
    cs252->children.push_back(projects);
    projects->children.push_back(papers);
    projects->children.push_back(demos);
    papers->children.push_back(buylow);
    papers->children.push_back(sellhigh);
    demos->children.push_back(market);

    int totalSize = diskSpace(*root, *root);
    cout << "\nTotal size of the file system: " << totalSize << " bytes" << endl;
  cout<<endl;
  

    // Output values for each node
    cout << "**** Node Values ****" << endl;
  cout<<"----------------------------\n";
    cout << "Root: " << root->name << "-> Size: " << root->size << " bytes" << endl;
    cout << "cs016: " << cs016->name << "-> Size: " << cs016->size << " bytes" << endl;
    cout << "grades: " << grades->name << "-> Size: " << grades->size << " bytes" << endl;
    cout << "homeworks: " << homeworks->name << "-> Size: " << homeworks->size << " bytes" << endl;
    cout << "programs: " << programs->name << "->Size: " << programs->size << " bytes" << endl;
    cout << "hw1: " << hw1->name << ", Size: " << hw1->size << " bytes" << endl;
    cout << "hw2: " << hw2->name << ", Size: " << hw2->size << " bytes" << endl;
    cout << "hw3: " << hw3->name << ", Size: " << hw3->size << " bytes" << endl;
    cout << "pr1: " << pr1->name << ", Size: " << pr1->size << " bytes" << endl;
    cout << "pr2: " << pr2->name << ", Size: " << pr2->size << " bytes" << endl;
    cout << "pr3: " << pr3->name << ", Size: " << pr3->size << " bytes" << endl;
  cout<<endl;
    cout << "cs252: " << cs252->name << ", Size: " << cs252->size << " bytes" << endl;
    cout << "projects: " << projects->name << ", Size: " << projects->size << " bytes" << endl;
    cout << "grades2: " << grades2->name << ", Size: " << grades2->size << " bytes" << endl;
    cout << "papers: " << papers->name << ", Size: " << papers->size << " bytes" << endl;
    cout << "demos: " << demos->name << ", Size: " << demos->size << " bytes" << endl;
    cout << "buylow: " << buylow->name << ", Size: " << buylow->size << " bytes" << endl;
    cout << "sellhigh: " << sellhigh->name << ", Size: " << sellhigh->size << " bytes" << endl;
    cout << "market: " << market->name << ", Size: " << market->size << " bytes" << endl;

    // Clean up memory (optional)
    delete root;
    delete cs016;
    delete grades;
    delete homeworks;
    delete programs;
    delete hw1;
    delete hw2;
    delete hw3;
    delete pr1;
    delete pr2;
    delete pr3;
    delete cs252;
    delete grades2;
    delete projects;
    delete papers;
    delete demos;
    delete buylow;
    delete sellhigh;
    delete market;

    return 0;
}
