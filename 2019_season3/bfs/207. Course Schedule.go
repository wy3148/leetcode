// 207. Course Schedule
// DescriptionHintsSubmissionsDiscussSolution
// There are a total of n courses you have to take, labeled from 0 to n-1.

// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

// Example 1:

// Input: 2, [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take.
//              To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: 2, [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take.
//              To take course 1 you should have finished course 0, and to take course 0 you should
//              also have finished course 1. So it is impossible.
// Note:

// The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// You may assume that there are no duplicate edges in the input prerequisites.

import "fmt"

func canFinish(numCourses int, prerequisites [][]int) bool {
	learned := make(map[int]struct{})

	if len(prerequisites) == 0 {
		return true
	}

	//numCourses : 0 n -1
	preq := make(map[int]map[int]struct{})
	canLearned := make(map[int]map[int]struct{})
	for i := 0; i < numCourses; i++ {
		preq[i] = make(map[int]struct{})
		canLearned[i] = make(map[int]struct{})
	}

	for _, v := range prerequisites {
		//v[0],v[1]
		preq[v[0]][v[1]] = struct{}{}

		//双向映射关系;学完一个课程，影响到的其他课程
		canLearned[v[1]][v[0]] = struct{}{}
	}

	var queue []int
	for k, v := range preq {
		if len(v) == 0 {
			queue = append(queue, k)
		}
	}

	for len(queue) > 0 {
		cur := queue[0]
		learned[cur] = struct{}{}

		for k, _ := range canLearned[cur] {
			delete(preq[k], cur)
			if len(preq[k]) == 0 {
				queue = append(queue, k)
			}
		}
		//queue pop out the front
		queue = queue[1:]
	}
	return len(learned) == numCourses
}

// https://leetcode.com/problems/course-schedule-iii/description/
https://leetcode.com/problems/course-schedule-iii/description/
hard level

