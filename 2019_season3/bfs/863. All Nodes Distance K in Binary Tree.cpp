
// 863. All Nodes Distance K in Binary Tree
//下面的算法是错误！！！！Warning!!!


/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

import "fmt"

var targetDepth int
func depth(root* TreeNode, target *TreeNode, cur int, found *bool){
    if root == nil || *found == true{
        return
    }
    if root == target{
        *found = true
        targetDepth = cur
        return
    }
    depth(root.Left,target,cur + 1,found)
    depth(root.Right,target,cur + 1,found)
}

func dist(node *TreeNode,target* TreeNode, K int) []int{
    if node == nil || target == nil || K < 0{
        return nil
    }
    
    if K == 0{
        return []int{node.Val}
    }
    
    var queue []*TreeNode
    queue = append(queue,node)
    var ret []int
    d := -1
    for len(queue) > 0 {
        d++
        size := len(queue)
        for i := 0; i < size; i++{
            node := queue[i]
            if d == K{
                ret = append(ret,node.Val)
            }
            if node.Left != nil  && node.Left != target {
                queue = append(queue,node.Left)
            }
            if node.Right != nil && node.Right != target{
                queue = append(queue,node.Right)
            }
        }
        queue = queue[size:]
        if d == K {
            break
        }
    }   
    return ret
}

func distanceK(root *TreeNode, target *TreeNode, K int) []int {
    if K == 0 {
        return []int{target.Val}
    }
    if root == nil || target == nil || K < 0 {
        return nil
    }
    
    //from target to child nodes
    ret := dist(target,target, K)
    
    if root != target{
        left := false
        right := false
        depth(root.Left, target,1,&left)
        depth(root.Right, target,1,&right)
        
        if K == targetDepth{
            ret = append(ret,root.Val)
            
            var r []int
            
            if left{
                r = dist(root.Left,target, K -1)   
            }            
 
            if right{
                r = dist(root.Right,target, K -1)   
            }   
            
            if r != nil{
                ret = append(ret,r...)
            }
            
            return ret
        }
        
        var r []int
        if K > targetDepth{
            //targetDepth + the other side of nodes
            if left{
                l := dist(root.Right,target, K-targetDepth - 1)
                if l != nil {
                    r = append(r,l...)
                }
            }
            
            if right{
                rr := dist(root.Left,target, K-targetDepth - 1)
                if rr != nil {
                    r = append(r,rr...)
                }
            }
        }else if left{
            r = dist(root.Left,target, targetDepth - K -1) 
        }else if right{
            r = dist(root.Right,target, targetDepth - K -1)    
        }
        if r != nil{
            ret = append(ret,r...)
        }
    }
    return ret
}
