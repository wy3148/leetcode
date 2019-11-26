// 785. Is Graph Bipartite?
// DescriptionHintsSubmissionsDiscussSolution
// Given an undirected graph, return true if and only if it is bipartite.

// Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.

// The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.

// Example 1:
// Input: [[1,3], [0,2], [1,3], [0,2]]
// Output: true
// Explanation: 
// The graph looks like this:
// 0----1
// |    |
// |    |
// 3----2
// We can divide the vertices into two groups: {0, 2} and {1, 3}.
// Example 2:
// Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
// Output: false
// Explanation: 
// The graph looks like this:
// 0----1
// | \  |
// |  \ |
// 3----2
// We cannot find a way to divide the set of nodes into two independent subsets.

func isBipartite(graph [][]int) bool {

    if len(graph) == 0 {
        return true
    }

    //range: 0 ---- len(graph) - 1;
    //default value :0 --not colored
    // 1--red color
    // -1 -- black color
    color := make([]int, len(graph))
    var queue []int
    
    for i := 0; i < len(graph); i++ {
        if color[i] == 0{
            color[i] = 1
            queue = append(queue,i)
        }
        
        for len(queue) > 0 {        
            cur := queue[0]
            for _, v := range graph[cur]{
                if color[v] == color[cur]{        
                    return false
                }else if color[v] == 0{
                    color[v] = -color[cur]
                    queue = append(queue,v)
                }
            }
            queue = queue[1:]
        }
    }
    return true
}



//dfs algothrgim




var color []int

func dfs(graph[][]int, cur int) bool{
    if color[cur] == 0{
        color[cur] = 1
        return dfs(graph,cur)
    }

    ///dfs 通常recursive function
    for _ , v := range graph[cur]{
        if color[v] == color[cur] {
            return false
        }else if color[v] == 0{
            color[v] = -color[cur]
            if dfs(graph,v) == false{
                return false
            }
        }
    }
    return true
}

func isBipartite(graph [][]int) bool {    
    color = make([]int,len(graph))
    for i :=0 ; i < len(graph); i++{    
        ret := dfs(graph,i)
        if !ret {
            return false
        }
    }
    return true
}


