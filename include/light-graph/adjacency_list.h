/*
 * adjacency_list.h
 *
 *  Created on: Apr 24, 2013
 *      Author: Leimi Chen 
 */

#ifndef LIGHT_GRAPH_ADJACENCY_LIST_H_
#define LIGHT_GRAPH_ADJACENCY_LIST_H_

#include <vector>
#include <cstddef>
#include <light-graph/basic_types.h>

namespace lgraph
{

class AdjacencyList
{
public:
	AdjacencyList(index_t n)
	: m_n(n)
	, m_m(0)
	, m_neighbors(n)
	{ }

	void add_edge(index_t u, index_t v)
	{
		m_neighbors[u].push_back(v);
		m_m++;
	}

	const std::vector<index_t>& neighbors(index_t u) const
	{
		return m_neighbors[u];
	}

	index_t num_vertices() const
	{
		return m_n;
	}

	index_t out_degree(index_t u) const
	{
		return m_neighbors[u].size();
	}

	index_t num_edges() const
	{
		return m_m;
	}

private:
	index_t m_n;
	index_t m_m;
	std::vector<std::vector<index_t> > m_neighbors;

};





}


#endif /* ADJACENCY_LIST_H_ */
