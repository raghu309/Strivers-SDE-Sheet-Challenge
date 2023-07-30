#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/

void dfs(graphNode* cur, map<graphNode*, graphNode*> &mpp) {
	mpp[cur] = new graphNode(cur->data);

	for(auto nxt:cur->neighbours) {
		if(mpp.count(nxt))
			continue;
		dfs(nxt, mpp);
	}
	for(auto child:cur->neighbours) {
		mpp[cur]->neighbours.push_back(mpp[child]);
	}
}

graphNode *cloneGraph(graphNode *node)
{
	map<graphNode*, graphNode*> mpp;
	dfs(node, mpp);
	return mpp[node];
}








