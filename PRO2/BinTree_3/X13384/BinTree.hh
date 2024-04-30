#ifndef BINTREE_HH
#define BINTREE_HH

#ifndef NO_DIAGRAM
#include <cassert>
#include <memory>
#endif


#include <string>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

// A BinTree<T> implements binary trees with values of type T.
template <typename T>
class BinTree {

  struct Node {
    T x;
    shared_ptr<Node> left;
    shared_ptr<Node> right;

    Node (const T& x, shared_ptr<Node> left, shared_ptr<Node> right)
      :   x(x), left(left), right(right)
    {   }

  };

  // A tree only holds a node pointer.
  shared_ptr<Node> p;

  // Constructs a tree from a node pointer.
  BinTree (shared_ptr<Node> p)
    :   p(p)
  {   }    
    
  // Notes:
  //   - default operator=() is good.
  //   - default destructor is good. Θ(n) where n is the number of nodes in the tree.
  //   - std::swap() already works by default.




  int inputformat, outputformat;
  static void checkFormat(int format) {
    if (format == POSTORDERFORMAT or
	format == LEFTVISUALFORMAT or
	format == VISUALFORMAT or
	format == INLINEFORMAT)
      return;
    std::cerr << "ERROR: wrong tree format" << std::endl;
    exit(1);
  }
  static void dieInputOutputBinTree(string s);
  static void dieWrongFormatTree();
  static void checkFormatCondition(bool condition);
  static int firstNonBlankPosInString(const string &s);
  static int lastNonBlankPosInString(const string &s);
  static string value2string(const T &value);
  static void string2value(const string &s, T &value);
  static void insertPrefixVectorString(string prefix, vector<string> &v);
  static void insertSpaceVectorString(int space, vector<string> &v);
  static int obtainRootPositionInString(const string &s);
  static int countNumberNodes(const BinTree<T> &t);
  static void readBinTreePostOrder(std::istream &is, BinTree<T> &t);
  static void writeBinTreePostOrderRec(std::ostream &os, const BinTree<T> &t);
  static void writeBinTreePostOrder(std::ostream &os, const BinTree<T> &t);
  static void readStringTree(int &itoken,const std::vector<std::pair<std::string,std::string> > &vtoken,BinTree<T> &t);
  static void readStringTree(const std::string &s,BinTree<T> &t);
  static void writeStringTreeRec(std::ostream &os,const BinTree<T> &t);
  static void writeStringTree(std::ostream &os,const BinTree<T> &t);
  static void readLeftVisualFormatRec(istream &is, int j, BinTree<T> &t);
  static void readLeftVisualFormat(istream &is, BinTree<T> &t);
  static vector<string> generateLeftVisualFormatRec(const BinTree<T> &t);
  static void readVisualFormatRec(const vector<string> &v, int i, int j, BinTree<T> &t);
  static void readVisualFormat(const vector<string> &v, BinTree<T> &t);
  static vector<string> generateVisualFormatRec(const BinTree<T> &t);
  static vector<string> generateVisualFormat(const BinTree<T> &t);

  
public:

  // Constructs an empty tree. Θ(1).
  BinTree ()
    :   p(nullptr)
  {
    inputformat = outputformat = INLINEFORMAT;
  }
    
  BinTree(const BinTree &t) {
    p = t.p;
    inputformat=t.inputformat;
    outputformat=t.outputformat;
  }
    
  BinTree &operator=(const BinTree &t) {
    inputformat=t.inputformat;
    outputformat=t.outputformat;
    p = t.p;
    return *this;
  }
	
  // Constructs a tree with a value x and no subtrees. Θ(1).
  explicit BinTree (const T& x) {
    inputformat = outputformat = INLINEFORMAT;
    p = make_shared<Node>(x, nullptr, nullptr);
  }

  // Constructs a tree with a value x and two subtrees left and right. Θ(1).
  explicit BinTree (const T& x, const BinTree& left, const BinTree& right) {
    inputformat = outputformat = INLINEFORMAT;
    p = make_shared<Node>(x, left.p, right.p);
  }

  // Tells if this tree is empty. Θ(1).
  bool empty () const {
    return not p;
  }
    
  // Returns the left subtree of this tree (cannot be empty). Θ(1).
  BinTree left () const {
    assert(not empty());
    BinTree t = BinTree(p->left);
    t.inputformat = inputformat;
    t.outputformat = outputformat;
    return t;
  }

  // Returns the right subtree of this tree (cannot be empty). Θ(1).
  BinTree right () const {
    assert(not empty());
    BinTree t = BinTree(p->right);
    t.inputformat = inputformat;
    t.outputformat = outputformat;
    return t;
  }

  // Returns the value of this tree (cannot be empty). Θ(1).
  const T& value () const {
    assert(not empty());
    return p->x;
  }



  // Fields for managing input/output.

  static const int POSTORDERFORMAT = 1;
  static const int LEFTVISUALFORMAT = 2;
  static const int VISUALFORMAT = 3;
  static const int INLINEFORMAT = 4;

  // Pre: true
  // Post: Sets inputformat of implicit tree and its descendants to 'format'
  void setInputFormat(int format) {
    checkFormat(format);
    inputformat = format;
  }

  // Pre: true
  // Post: Sets outputformat of implicit tree and its descendants to 'format'
  void setOutputFormat(int format) {
    checkFormat(format);
    outputformat = format;
  }

  // Pre: true
  // Post: Sets inputformat and outputformat of implicit tree and its descendants to 'format'
  void setInputOutputFormat(int format) {
    setInputFormat(format);
    setOutputFormat(format);
  }

  // Pre: true
  // Post: returns current inputformat
  int getInputFormat() const {
    return inputformat;
  }

  // Pre: true
  // Post: returns current outputformat
  int getOutputFormat() const {
    return outputformat;
  }

  
  // writing operator <<
  /* Pre: true */
  /* Post: a representation of t is written on os deppending on current value of attribute 'outputformat' */
  template <class U> friend std::ostream& operator<<(std::ostream &os, const BinTree<U> &t);

  // reading operator >>
  // Pre: 'is' contains a representation of a binary tree deppending on current value of attribute 'inputformat'.
  // Post: t is assigned the tree value read from 'is'
  template <class U> friend std::istream& operator>>(std::istream &is, BinTree<U> &t);

  
};



////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
// Common auxiliary functions for generating format


const int MINNUMHYPENSDESCENDANT = 4;
const int MINSPACEBETWEENSUBTREES = 4;

template<typename T>
void BinTree<T>::dieInputOutputBinTree(string s)
{
  std::cerr << s << std::endl;
  exit(1);
}

template<typename T>
void BinTree<T>::dieWrongFormatTree()
{
  dieInputOutputBinTree("Error: Wrong format input tree");
}

template<typename T>
void BinTree<T>::checkFormatCondition(bool condition) {
  if (not condition) dieWrongFormatTree();
}

template<typename T>
int BinTree<T>::firstNonBlankPosInString(const string &s) {
  int i = 0;
  while (i < int(s.size()) and s[i] == ' ') ++i;
  return i;
}

template<typename T>
int BinTree<T>::lastNonBlankPosInString(const string &s) {
  int i = int(s.size())-1;
  while (i >= 0 and s[i] == ' ') --i;
  return i;
}

template<typename T>
string BinTree<T>::value2string(const T &value)
{
  ostringstream mycout;
  if (not (mycout << value))
    dieInputOutputBinTree("Error: We could not transform a value into a string");
  string s = mycout.str();
  if (int(s.size()) == 0)
    dieInputOutputBinTree("Error: length 0 is not allowed for strings describing values");
  for (int i = 0; i < int(s.size()); ++i)
    if (s[i] == ' ')
      dieInputOutputBinTree("Error: white spaces are not allowed for strings describing values");
  return s;
}

template<typename T>
void BinTree<T>::string2value(const string &s, T &value)
{
  istringstream mycin(s);
  if (not (mycin >> value))
    dieInputOutputBinTree("Error: We could not transform a string into a value");
  string rest;
  if (mycin >> rest)
    dieInputOutputBinTree("Error: We could not transform a string into a value");
}

template<typename T>
void BinTree<T>::insertPrefixVectorString(string prefix, vector<string> &v) {
  for (int i = 0; i < int(v.size()); ++i)
    v[i] = prefix + v[i];
}

template<typename T>
void BinTree<T>::insertSpaceVectorString(int space, vector<string> &v) {
  insertPrefixVectorString(string(space, ' '), v);
}

template<typename T>
int BinTree<T>::obtainRootPositionInString(const string &s) {
  return (firstNonBlankPosInString(s)+int(s.size())-1)/2;
}

template <class T>
int BinTree<T>::countNumberNodes(const BinTree<T> &t)
{
  if (t.empty()) return 0;
  return 1 + countNumberNodes(t.left()) + countNumberNodes(t.right());
}


////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
// Code reading and writing POSTORDERFORMAT

template <class T>
void BinTree<T>::readBinTreePostOrder(std::istream &is, BinTree<T> &t)
{  
  int size;
  std::stack<BinTree<T> > s;

  is >> size;  
  while (size > 0) {
    T node;
    int numchildren; // 0: zero, -1: only left, 1: only right, 2: two
    is >> node >> numchildren;
    if (numchildren == 0) {
      s.push(BinTree<T>(node, BinTree<T>(), BinTree<T>()));
    } else if (numchildren == -1) {
      BinTree<T> left = s.top();
      s.pop();
      s.push(BinTree<T>(node, left, BinTree<T>()));
    } else if (numchildren == 1) {
      BinTree<T> right = s.top();
      s.pop();
      s.push(BinTree<T>(node, BinTree<T>(), right));
    } else {
      BinTree<T> right = s.top();
      s.pop();
      BinTree<T> left = s.top();
      s.pop();
      s.push(BinTree<T>(node, left, right));
    }
    --size;
  }
  if (not s.empty()) t = s.top();
}

template <class T>
void BinTree<T>::writeBinTreePostOrderRec(std::ostream &os, const BinTree<T> &t)
{
  if (t.empty()) return;
  writeBinTreePostOrderRec(os, t.left());
  writeBinTreePostOrderRec(os, t.right());
  os << t.value() << " ";
  if (t.left().empty() and t.right().empty()) os << 0;
  else if (t.left().empty()) os << 1;
  else if (t.right().empty()) os << -1;
  else os << 2;
  os << endl;
}

template <class T>
void BinTree<T>::writeBinTreePostOrder(std::ostream &os, const BinTree<T> &t)
{
  os << countNumberNodes(t) << endl;
  writeBinTreePostOrderRec(os, t);
}
  
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
// Code reading and writing INLINEFORMAT

template<typename T>
void BinTree<T>::readStringTree(int &itoken,const std::vector<std::pair<std::string,std::string> > &vtoken,BinTree<T> &t)
{
  if (itoken>=int(vtoken.size()) or vtoken[itoken].first!="value") {
    t=BinTree<T>();
    return;
  }
  std::istringstream mycin(vtoken[itoken].second);
  T value;
  mycin>>value;
  itoken++;
  if (itoken>=int(vtoken.size()) or vtoken[itoken].first!="(") {
    t=BinTree<T>(value, BinTree<T>(), BinTree<T>());
    return;
  }
  itoken++;
  BinTree<T> left;
  readStringTree(itoken,vtoken,left);
  if (itoken>=int(vtoken.size()) or vtoken[itoken].first!=",") {
    t=BinTree<T>(value,left,BinTree<T>());
    if (itoken<int(vtoken.size()) and vtoken[itoken].first==")")
      itoken++;
    return;
  }
  itoken++;
  BinTree<T> right;
  readStringTree(itoken,vtoken,right);
  if (itoken<int(vtoken.size()) and vtoken[itoken].first==")")
    itoken++;
  t=BinTree<T>(value,left,right);
}

template<typename T>
void BinTree<T>::readStringTree(const std::string &s,BinTree<T> &t)
{
  std::vector<std::pair<std::string,std::string> > vtoken;
  int iant=0;
  for (int i=0;i<int(s.size());i++) {
    if (s[i]==',' or s[i]=='(' or s[i]==')') {
      if (iant<i)
	vtoken.push_back(std::pair<std::string,std::string> ("value",s.substr(iant,i-iant)));
      iant=i+1;
      vtoken.push_back(std::pair<std::string,std::string> (std::string(1,s[i]),""));
    }
  }
  if (iant<int(s.size()))
    vtoken.push_back(std::pair<std::string,std::string> ("value",s.substr(iant)));
  int itoken=0;
  readStringTree(itoken,vtoken,t);
}

template<typename T>
void BinTree<T>::writeStringTreeRec(std::ostream &os,const BinTree<T> &t)
{
  if (t.empty()) return;
  os<<t.value();
  BinTree<T> left=t.left();
  BinTree<T> right=t.right();
  if (left.empty() and right.empty()) return;
  os<<"(";
  writeStringTreeRec(os,left);
  os<<",";
  writeStringTreeRec(os,right);
  os<<")";
}

template<typename T>
void BinTree<T>::writeStringTree(std::ostream &os,const BinTree<T> &t)
{
  if (t.empty()) {
    os<<"()";
    return;
  }
  writeStringTreeRec(os,t);
}

////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
// Code reading and writing LEFTVISUALFORMAT

template<typename T>
void BinTree<T>::readLeftVisualFormatRec(istream &is, int j, BinTree<T> &t) {
  string line;
  getline(is, line);
  string s = line.substr(j);
  if (s == ".") {
    t = BinTree<T> ();
    return;
  }
  if (int(s.size()) == 0 or s[0] != '[')
    dieInputOutputBinTree("Error: Wrong format for input tree");
  if (s[int(s.size())-1] != ']')
    dieInputOutputBinTree("Error: Wrong format for input tree");
  T value;
  string2value(s.substr(1,int(s.size())-2), value);
  BinTree<T> right;
  readLeftVisualFormatRec(is, j+4, right);
  BinTree<T> left;
  readLeftVisualFormatRec(is, j+4, left);
  t = BinTree<T> (value, left, right);
}

template<typename T>
void BinTree<T>::readLeftVisualFormat(istream &is, BinTree<T> &t) {
  readLeftVisualFormatRec(is, 0, t);
}

template<typename T>
vector<string> BinTree<T>::generateLeftVisualFormatRec(const BinTree<T> &t) {
  vector<string> result;
  if (t.empty()) {
    result.push_back(".");
    return result;
  }
  string rootstring = value2string(t.value());
  vector<string> leftresult = generateLeftVisualFormatRec(t.left());
  vector<string> rightresult = generateLeftVisualFormatRec(t.right());
  result.push_back("[" + rootstring + "]");
  for (int i = 0; i < int(rightresult.size()); ++i) {
    if (i == 0)
      result.push_back(" \\__" + rightresult[i]);
    else
      result.push_back(" |  " + rightresult[i]);
  }
  for (int i = 0; i < int(leftresult.size()); ++i) {
    if (i == 0)
      result.push_back(" \\__" + leftresult[i]);
    else
      result.push_back("    " + leftresult[i]);
  }
  return result;
}

////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
// Code reading and writing VISUALFORMAT


template<typename T>
void BinTree<T>::readVisualFormatRec(const vector<string> &v, int i, int j, BinTree<T> &t) {
  if (i < 0 or int(v.size()) <= i or j < 0 or int(v[i].size()) <= j or v[i][j] == ' ') {
    t = BinTree<T> ();
    return;
  }
  const string &line = v[i];
  int jini = j;
  while (jini > 0 and line[jini-1] != ' ') jini--;
  int jend = j;
  while (jend+1 <= int(line.size())-1 and line[jend+1] != ' ') jend++;
  string rootstring = line.substr(jini, jend-jini+1);
  T root;
  string2value(rootstring, root);
  if (int(v.size()) <= i+1) {
    t = BinTree<T> (root, BinTree<T> (), BinTree<T> ());
    return;
  }
  const string &linedown = v[i+1];
  int jdown = jini;
  while (jdown < int(linedown.size()) and jdown <= jend and linedown[jdown] == ' ') jdown++;
  if (int(linedown.size()) <= jdown or jend < jdown) {
    t = BinTree<T> (root, BinTree<T> (), BinTree<T> ());
    return;
  }
  checkFormatCondition(linedown[jdown] == '|');
  checkFormatCondition(i+3 < int(v.size()));
  const string &line2down = v[i+2];
  const string &line3down = v[i+3];
  int jleft = jdown-1;
  BinTree<T> left;
  if (jleft >= 0 and jleft < int(line2down.size()) and line2down[jleft] == '-') {
    while (jleft >= 0 and line2down[jleft] == '-') jleft--;
    checkFormatCondition(0 <= jleft and jleft < int(line3down.size()) and line3down[jleft] == '|');
    readVisualFormatRec(v, i+4, jleft, left);
  }
  int jright = jdown+1;
  BinTree<T> right;
  if (jright < int(line2down.size()) and line2down[jright] == '-') {
    while (jright >= 0 and jright < int(line2down.size()) and line2down[jright] == '-') jright++;
    checkFormatCondition(0 <= jright and jright < int(line3down.size()) and line3down[jright] == '|');
    readVisualFormatRec(v, i+4, jright, right);
  }
  t = BinTree<T> (root, left, right);
}

template<typename T>
void BinTree<T>::readVisualFormat(const vector<string> &v, BinTree<T> &t) {
  if (int(v.size()) == 0) {
    t = BinTree<T> ();
    return;
  }
  readVisualFormatRec(v, 0, firstNonBlankPosInString(v[0]), t);
}

template<typename T>
vector<string> BinTree<T>::generateVisualFormatRec(const BinTree<T> &t) {
  if (t.empty()) return vector<string> ();
  string rootstring = value2string(t.value());
  int rootrelativepos = (int(rootstring.size())-1)/2;
  vector<string> leftresult = generateVisualFormatRec(t.left());
  int leftrootpos = 0;
  if (int(leftresult.size()) > 0)
    leftrootpos = obtainRootPositionInString(leftresult[0]);
  vector<string> rightresult = generateVisualFormatRec(t.right());
  int rightrootpos = 0;
  if (int(rightresult.size()) > 0)
    rightrootpos = obtainRootPositionInString(rightresult[0]);
  vector<string> result;
  if (int(leftresult.size()) == 0 and int(rightresult.size()) == 0) {
    result.push_back(rootstring);
    return result;
  }
  if (int(leftresult.size()) == 0) {
    int rootpos = rightrootpos-MINNUMHYPENSDESCENDANT-1;
    if (rootpos-rootrelativepos < 0) {
      insertSpaceVectorString(-(rootpos-rootrelativepos), rightresult);
      rightrootpos += -(rootpos-rootrelativepos);
      rootpos = rootrelativepos;
    }
    result.push_back(string(rootpos-rootrelativepos, ' ') + rootstring);
    result.push_back(string(rootpos, ' ') + string(1, '|'));
    result.push_back(string(rootpos+1, ' ') + string(rightrootpos-rootpos-1, '-'));
    result.push_back(string(rightrootpos, ' ') + string(1, '|'));
    for (int i = 0; i < int(rightresult.size()); ++i)
      result.push_back(rightresult[i]);
    return result;
  }
  if (int(rightresult.size()) == 0) {
    int rootpos = leftrootpos+MINNUMHYPENSDESCENDANT+1;
    if (rootpos-rootrelativepos < 0) {
      insertSpaceVectorString(-(rootpos-rootrelativepos), leftresult);
      leftrootpos += -(rootpos-rootrelativepos);
      rootpos = rootrelativepos;
    }
    result.push_back(string(rootpos-rootrelativepos, ' ') + rootstring);
    result.push_back(string(rootpos, ' ') + string(1, '|'));
    result.push_back(string(leftrootpos+1, ' ') + string(max(0,rootpos-leftrootpos-1), '-'));
    result.push_back(string(leftrootpos, ' ') + string(1, '|'));
    for (int i = 0; i < int(leftresult.size()); ++i)
      result.push_back(leftresult[i]);
    return result;
  }
  int addspace = leftrootpos + 2 + 2*MINNUMHYPENSDESCENDANT - rightrootpos;
  for (int i = 0; i < int(leftresult.size()) and i < int(rightresult.size()); ++i)
    addspace = max(addspace, int(leftresult[i].size())-firstNonBlankPosInString(rightresult[i])+MINSPACEBETWEENSUBTREES);
  if ((rightrootpos+addspace-leftrootpos)%2 == 1) addspace++;
  if (addspace > 0) {
    insertSpaceVectorString(addspace, rightresult);
    rightrootpos += addspace;
  } else if (addspace < 0) {
    insertSpaceVectorString(-addspace, leftresult);
    leftrootpos += -addspace;
  }
  int rootpos = (leftrootpos+rightrootpos)/2;
  if (rootpos-rootrelativepos < 0) {
    insertSpaceVectorString(-(rootpos-rootrelativepos), leftresult);
    insertSpaceVectorString(-(rootpos-rootrelativepos), rightresult);
    leftrootpos += -(rootpos-rootrelativepos);
    rightrootpos += -(rootpos-rootrelativepos);
    rootpos = rootrelativepos;
  }
  result.push_back(string(rootpos-rootrelativepos, ' ') + rootstring);
  result.push_back(string(rootpos, ' ') + string(1, '|'));
  result.push_back(string(leftrootpos+1, ' ') + string(rootpos-leftrootpos-1, '-') + string(1, ' ') +
		   string(max(0,rightrootpos-rootpos-1), '-'));
  result.push_back(string(leftrootpos, ' ') + string(1, '|') + string(rightrootpos-leftrootpos-1, ' ') + string(1, '|'));
  //cout << "Adding left and right result" << endl;
  for (int i = 0; i < int(leftresult.size()) or i < int(rightresult.size()); ++i) {
    if (i < int(leftresult.size()) and i < int(rightresult.size())) {
      string &leftline = leftresult[i];
      string &rightline = rightresult[i];
      int leftsize = int(leftline.size());
      int rightsize = int(rightline.size());
      int size = max(leftsize, rightsize);
      string line(size, ' ');
      for (int j = 0; j < size; ++j) {
	if (j < leftsize and leftline[j] != ' ') line[j] = leftline[j];
	else if (j < rightsize and rightline[j] != ' ') line[j] = rightline[j];
      }
      result.push_back(line);
    } else if (i < int(leftresult.size())) {
      result.push_back(leftresult[i]);
    } else {
      result.push_back(rightresult[i]);
    }
  }
  return result;
}

template <class T>
vector<string> BinTree<T>::generateVisualFormat(const BinTree<T> &t) {
  vector<string> v = generateVisualFormatRec(t);
  v.push_back(string());
  return v;
}

////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
// Write tree on an output stream

template <class T>
std::ostream& operator<<(std::ostream &os, const BinTree<T> &t) {
  int format = t.getOutputFormat();
  if (format == BinTree<T>::INLINEFORMAT) {
    BinTree<T>::writeStringTree(os, t);
    return os;
  }
  if (format == BinTree<T>::POSTORDERFORMAT) {
    BinTree<T>::writeBinTreePostOrder(os, t);
    return os;
  }
  vector<string> result;
  if (format == BinTree<T>::LEFTVISUALFORMAT)
    result = BinTree<T>::generateLeftVisualFormatRec(t);
  else if (format == BinTree<T>::VISUALFORMAT)
    result = BinTree<T>::generateVisualFormat(t);
  for (int i = 0; i < int(result.size()); ++i) {
    os << result[i];
    if (i < int(result.size())-1) os << std::endl;
  }
  return os;
}

////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
// Read tree from an input stream

template <class T>
std::istream& operator>>(std::istream &is, BinTree<T> &t) {
  int inputformat = t.getInputFormat();
  int outputformat = t.getOutputFormat();
  if (inputformat == BinTree<T>::INLINEFORMAT) {
    string s;
    is >> s;
    BinTree<T>::readStringTree(s, t);
    t.setInputFormat(inputformat);
    t.setOutputFormat(outputformat);
    return is;
  }
  if (inputformat == BinTree<T>::POSTORDERFORMAT) {
    BinTree<T>::readBinTreePostOrder(is, t);
    t.setInputFormat(inputformat);
    t.setOutputFormat(outputformat);
    return is;
  }
  //is.clear();
  //is.ignore();
  if (inputformat == BinTree<T>::LEFTVISUALFORMAT) {
    BinTree<T>::readLeftVisualFormat(is, t);
    t.setInputFormat(inputformat);
    t.setOutputFormat(outputformat);
    return is;
  }
  vector<string> v;
  string line;
  while (getline(is, line) and line != "")
    v.push_back(line);
  BinTree<T>::readVisualFormat(v, t);
  t.setInputFormat(inputformat);
  t.setOutputFormat(outputformat);
  return is;
}

#endif

