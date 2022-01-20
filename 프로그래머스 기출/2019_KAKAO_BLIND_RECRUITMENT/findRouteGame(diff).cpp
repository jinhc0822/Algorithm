#include <vector>
#include <algorithm>
using namespace std;

/*2022.01.19
노드 규칙 5, 6번을 어떻게든 구현하려고 했지만 실패.. 테스트 케이스의 반만 맞았다. 근데 왜 틀린지 모르겠음. 
그래서 트리를 만들어 재귀를 이용했다. 이 방법을 먼저 이용해야한다는 생각은 왜 안 들었을까.
생각해보면 예전에 학교에서 트리 배울 때 재귀를 사용했던 것 같은데 정말 기본적인 거였다.. 최소 힙이었나
뭔가 만들 때 분명히 이 방식으로 만들었던 것 같다..*/

struct Tree {
    int idx;
    int x;
    int y;
    Tree* left;
    Tree* right;
};
vector<int> pre, post;

void preorder(Tree* cur) {
    if (cur == NULL)
        return;
    pre.push_back(cur->idx);
    preorder(cur->left);
    preorder(cur->right);
}
void postorder(Tree* cur) {
    if (cur == NULL)
        return;
    postorder(cur->left);
    postorder(cur->right);
    post.push_back(cur->idx);
}
bool comp(Tree a, Tree b) {
    if (a.y != b.y)
        return a.y > b.y;
    else
        return a.x < b.x;
}
void makeTree(Tree* root, Tree* node) {
    if (root->x > node->x) {
        if (root->left == NULL) {
            root->left = node;
            return;
        }
        makeTree(root->left, node);
    }
    else {
        if (root->right == NULL) {
            root->right = node;
            return;
        }
        makeTree(root->right, node);
    }
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Tree> tree;
    for (int i = 0; i < nodeinfo.size(); i++)
        tree.push_back({ i + 1, nodeinfo[i][0], nodeinfo[i][1], NULL, NULL });
    sort(tree.begin(), tree.end(), comp);
    Tree* root = &tree[0];
    for (int i = 1; i < tree.size(); i++)
        makeTree(root, &tree[i]);
    preorder(root);
    postorder(root);
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}