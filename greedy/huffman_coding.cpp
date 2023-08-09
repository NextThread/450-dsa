struct Node
{
  char data;
  unsigned int freq;
  Node *left, *right;
  Node(char data, unsigned int freq, Node *left = 0, Node *right = 0)
  {
    this->data = data;
    this->freq = freq;
    this->left = left;
    this->right = right;
  }
};
class comp
{
public:
  bool operator()(Node *l, Node *r)
  {
    return l->freq > r->freq;
  }
};
class Solution
{
public:
  vector<string> huffmanCodes(string S, vector<int> f, int N)
  {
    priority_queue<Node *, vector<Node *>, comp> pq;
    for (int i = 0; i < f.size(); i++)
      pq.push(new Node(S[i], f[i]));

    while (pq.size() > 1)
    {
      Node *l = pq.top();
      pq.pop();
      Node *r = pq.top();
      pq.pop();
      Node *top = new Node('$', l->freq + r->freq, l, r);
      pq.push(top);image.png
    }
    vector<string> res;
    printHcode(pq.top(), "", res);
    return res;
  }
  void printHcode(Node *root, string str, vector<string> &res)
  {
    if (!root)
      return;
    if (root->data != '$')
      res.push_back(str);
    printHcode(root->left, str + '0', res);
    printHcode(root->right, str + '1', res);
  }
};