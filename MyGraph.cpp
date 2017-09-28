#include <iostream>
#include <cassert>
#include <cstring>
#include <queue>

using namespace std;

//图的顶点的实现
class Edge{
	public:
		int from;
		int to;
		int weight;
		Edge(int f, int t, int w)
		{
			from = f;
			to = t;
			weight = w;
		}
};

//图结构的实现
class Graph{
	public:
		int num_v;
		int num_e;
		int **adj;
		int *mark;
		Graph(int num_vertex)
		{
			num_v = num_vertex;
			mark = new int[num_v];
			adj = new int*[num_v];
			for(int i = 1; i <= num_v; i++)
				adj[i] = new int[num_v];
			for(int i = 0; i <= num_v; i++)
				for(int j = 0; j <= num_v; j++)
					adj[i][j] = 0;
			for(int i = 0; i <= num_v; i++)
				mark[i] = 0;
		}
		Graph() {delete []adj; delete []mark;}
		//顶点v的第一条边
		Edge first_edge(int v)
		{
			for(int i = 1; i <= num_v; i++)
				if(adj[v][i] > 0)
				{
					Edge e(v, i, adj[v][i]);
					return e;
				}
			Edge e(v, v, 0);
			return e;
		}
		//边e的下一条边
		Edge next_edge(Edge e)
		{
			for(e.to++; e.to <= num_v; e.to++)
			{
				if(is_edge(e.from, e.to))
				{
					e.weight = adj[e.from][e.to];
					return e;
				}
			}
			e.weight = 0;
			return e;
		}
		//边的增删查改
		void set_edge(int from_v, int to_v, int weight)
		{
			adj[from_v][to_v] = weight;
		}
		void delete_edge(int from_v, int to_v)
		{
			adj[from_v][to_v] = 0;
		}
		bool is_edge(int from_v, int to_v)
		{
			if(adj[from_v][to_v] != 0) return true;
			return false;
		}
		void init_mark()
		{
			for(int i = 0; i <= num_v; i++)
				mark[i] = false;
		}
		//图的遍历
		void dfs(int v)
		{
				if(mark[v]) return;
				mark[v] = true;
				cout << v << " ";
				for(Edge e = first_edge(v); e.to <= num_v; e = next_edge(e))
					if(!mark[e.to]) dfs(e.to);
		}
		void bfs(int v)
		{
			if(mark[v]) return;
			mark[v] = true;
			queue<int> q;
			q.push(v);
			while(!q.empty())
			{
				int u = q.front();
				cout << u << " ";
				q.pop();
				for(Edge e = first_edge(u); e.to <= num_v; e = next_edge(e))
				{
					if(!mark[e.to])
					{
						mark[e.to] = true;
						q.push(e.to);
					}
				}
			}
		}
		void traverse_dfs()
		{
				init_mark();
				for(int i = 1; i <= num_v; i++)
					dfs(i);
				cout << endl;
		}
		void traverse_bfs()
		{
				init_mark();
				for(int i = 1; i <= num_v; i++)
					bfs(i);
				cout << endl;
		}
		//图的拓补排序
		void init_indegree(int *indegree)
		{
			for(int i = 0; i <= num_v; i++)
				indegree[i] = 0;
			for(int i = 1; i <= num_v; i++)
				for(int j = 1; j <= num_v; j++)
					if(adj[i][j] != 0) indegree[j]++;
		}
		void topsort_bfs()
		{
			init_mark();
			queue<int> q;
			int indegree[num_v+1];
			init_indegree(indegree);
			for(int i = 1; i <= num_v; i++)
			 		if(indegree[i] == 0)
						q.push(i);
			if(q.empty()) return;
			while(!q.empty())
			{
				int u = q.front();
				q.pop();
				cout << u << " ";
				mark[u] = true;
				for(Edge e = first_edge(u); e.to <= num_v; e = next_edge(e))
				{
					if(!mark[e.to])
					{
						indegree[e.to]--;
						if(indegree[e.to] == 0)
							q.push(e.to);
					}
				}
			}
			cout << endl;
		}
		void topsort_dfs()
		{
			int *result = new int[num_v];
			init_mark();
			int index = 0;
			for(int i = 1; i <= num_v; i++)
					do_topsort(i, index, result);
			for(int i = num_v-1; i >= 0; i--)
				cout << result[i] << " ";
			cout << endl;
			delete [] result;
		}
		void do_topsort(int v, int &index, int *result)
		{
			if(mark[v]) return;
			mark[v] = true;
			for(Edge e = first_edge(v); e.to <= num_v; e = next_edge(e))
				if(!mark[e.to]) do_topsort(e.to, index, result);
			result[index] = v;
			index++;
		}
};

int main()
{
	Graph g(5);
	g.set_edge(1, 2, 1);
	g.set_edge(1, 3, 1);
	g.set_edge(2, 4, 1);
  g.set_edge(3, 5, 1);
	//g.set_edge(3, 1, 1);
	g.traverse_dfs();
	g.traverse_bfs();
	g.topsort_bfs();
	g.topsort_dfs();

	//cout << g.next_edge(g.first_edge(1)).weight << endl;
	return 0;
}
