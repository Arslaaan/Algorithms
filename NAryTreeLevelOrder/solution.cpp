#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {};

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        this->children = _children;
        this->val = _val;
    }
};

class Solution1 {
public:
    vector<vector<int>> levelOrder(Node *root) {
        queue<Node *> firstQueue;
        queue<Node *> secondQueue;
        vector<vector<int>> result;

        if (root != nullptr) {
            firstQueue.push(root);
        }

        while (!firstQueue.empty() || !secondQueue.empty()) {
            queue<Node *> *currentQueue = &firstQueue;
            queue<Node *> *nextQueue = &secondQueue;

            if (firstQueue.empty()) {
                currentQueue = &secondQueue;
                nextQueue = &firstQueue;
            }

            vector<int> levelVal;
            levelVal.reserve(currentQueue->size());
            while (!currentQueue->empty()) {
                Node *currentNode = currentQueue->front();

                levelVal.push_back(currentNode->val);
                for (Node *child: currentNode->children) {
                    nextQueue->push(child);
                }
                currentQueue->pop();
            }
            result.push_back(move(levelVal));
        }
        return result;
    }
};
