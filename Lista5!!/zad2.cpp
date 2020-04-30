#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

using Pair = pair<int, int>;

class Graph
{
public:
	int size;
	int max_id;
	vector<vector<Pair>> adj_list;
	unordered_map<string, int> nodes_names;
	unordered_map<int, string> nodes_ids;
	
	bool node_exists(int node) {
		return nodes_ids.find(node) != nodes_ids.end();
	}

	bool node_exists(string node) {
		return nodes_names.find(node) != nodes_names.end();
	}

	bool edge_exists(int begin, int end) {
		if (!node_exists(begin) || !node_exists(end))
			return false;
		for (Pair p : adj_list[begin])
			if (p.first == end)
				return true;
		return false;
	}

	Graph(): size(0), max_id(-1) {}

	int Size() const {
		return size;
	}

	void add_node(int node, string node_name) {
		if (node_exists(node) || node_exists(node_name)) {
			cout << "This node already exists!\n";
			return;
		}
		++size;
		if (node > max_id)
			max_id = node;
			
		nodes_names[node_name] = node;
		nodes_ids[node] = node_name;
		adj_list.resize(size);
	}

	void remove_node(int id) {
		if (!node_exists(id))
			throw runtime_error("Node is not valid!");

		for (int i = 0; i <= max_id; ++i) {
			if (edge_exists(id, i))
				remove_edge(id, i);
			if (edge_exists(i, id))
				remove_edge(i, id);
		}

		--size;
		if (id == max_id)
			--max_id;

		string name = nodes_ids.at(id);
		nodes_ids.erase(id);
		nodes_names.erase(name);
	}

	void remove_node(string name) {
		if (!node_exists(name))
			throw runtime_error("Node is not valid!");
		remove_node(nodes_names.at(name));
	}

	void add_edge(int begin, int end, int weight) {
		if (!node_exists(begin) || !node_exists(end))
			throw runtime_error("One or two nodes from edge is not valid!");
		adj_list[begin].push_back(make_pair(end, weight));
	}

	void add_edge(string begin, string end, int weight) {
		if (!node_exists(begin) || !node_exists(end))
			throw runtime_error("One or two nodes from edge is not valid!");
		int begin_id = nodes_names.at(begin);
		int end_id = nodes_names.at(end);
		add_edge(begin_id, end_id, weight);
	}

	void remove_edge(int begin, int end) {
		if (!node_exists(begin) || !node_exists(end))
			throw runtime_error("One or two nodes from edge is not valid!");

		for (auto it = adj_list[begin].begin(); it != adj_list[begin].end(); ++it) {
			if ((*it).first == end) {
				adj_list[begin].erase(it);
				break;
			}
		}
	}

	void remove_edge(string begin, string end) {
		if (!node_exists(begin) || !node_exists(end))
			throw runtime_error("One or two nodes from edge is not valid!");
		int begin_id = nodes_names.at(begin);
		int end_id = nodes_names.at(end);
		remove_edge(begin_id, end_id);
	}

	void change_weight(int begin, int end, int new_weight) {
		if (!node_exists(begin) || !node_exists(end))
			throw runtime_error("One or two nodes from edge is not valid!");

		for (auto it = adj_list[begin].begin(); it != adj_list[begin].end(); ++it) {
            if ((*it).first == end) {
                (*it).second = new_weight;
                break;
            }
        }	
	}

	void change_weight(string begin, string end, int new_weight) {
		if (!node_exists(begin) || !node_exists(end))
			throw runtime_error("One or two nodes from edge is not valid!");
		int begin_id = nodes_names.at(begin);
		int end_id = nodes_names.at(end);
		change_weight(begin_id, end_id, new_weight);
	}
	
	bool is_path(int begin, int end) {
		if (!node_exists(begin) || !node_exists(end))
			return false;
		
		if (begin == end) 
			return true; 

		vector<bool> visited(max_id, false);
		queue<int> q; 
		visited[begin] = true; 
		q.push(begin);  
	
		while (!q.empty()) 
		{  
			int id = q.front(); 
			q.pop(); 
			for (auto i = adj_list[id].begin(); i != adj_list[id].end(); ++i) 
			{ 
				if ((*i).first == end) 
					return true; 
	 
				if (!visited[(*i).first]) 
				{ 
					visited[(*i).first] = true; 
					q.push((*i).first); 
				} 
			} 
		}  
		return false; 
	}

	bool is_path(string begin, string end) {
		if (!node_exists(begin) || !node_exists(end))
			return false;
		int begin_id = nodes_names.at(begin);
		int end_id = nodes_names.at(end);
		return is_path(begin_id, end_id);
	}

	void print()
	{
		for (int i = 0; i <= this->max_id; ++i)
		{
			if (!node_exists(i))
				continue;

			for (Pair v : this->adj_list[i])
				cout << "(" << i << ", " << v.first <<
						", " << v.second << ", " << this->nodes_ids.at(i) <<
						 ", " << this->nodes_ids.find(v.first)->second << ") ";
			cout << endl;
		}
	}
};

int main()
{
	/*vector<Edge> edges =
	{
		{0, 1, 6, "zero", "first"},
		{1, 2, 7, "first", "second"},
		{2, 0, 5, "second", "zero"},
		{2, 1, 4, "second", "first"},
		{3, 2, 10, "third", "second"},
		{4, 5, 1, "fourth", "fifth"},
		{5, 4, 3, "fifth", "fourth"}
	};
	
	constexpr int number_of_nodes = 6;
	*/
	Graph graph;
	graph.add_node(0, "zero");
	graph.add_node(1, "first");
	graph.add_node(2, "second");
	graph.add_node(3, "third");
	graph.add_node(4, "fourth");
	graph.add_node(5, "fifth");

	graph.add_edge(0, 1, 6);
	graph.add_edge(1, 2, 7);
	graph.add_edge(2, 0, 5);
	graph.add_edge(2, 1, 4);
	graph.add_edge(3, 2, 10);
	graph.add_edge(4, 5, 1);
	graph.add_edge(5, 4, 3);

	graph.print();

	return 0;
}
