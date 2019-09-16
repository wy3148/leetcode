// 658. Find K Closest Elements
// DescriptionHintsSubmissionsDiscussSolution
// Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

// Example 1:
// Input: [1,2,3,4,5], k=4, x=3
// Output: [1,2,3,4]
// Example 2:
// Input: [1,2,3,4,5], k=4, x=-1
// Output: [1,2,3,4]
// Note:
// The value k is positive and will always be smaller than the length of the sorted array.
// Length of the given array is positive and will not exceed 104
// Absolute value of elements in the array and x will not exceed 104

func findClosestElements(arr []int, k int, x int) []int {
    var ret []int
    if len(arr) == 0 {
        return ret
    }
    
    l := 0
    r := len(arr) - 1
    pos := -1
    
    for l + 1 < r {
        mid := (l + r) / 2 
        if arr[mid] == x {
            pos = mid
            break
        }else if (arr[mid] > x){
            r = mid
        }else{
            l = mid
        }    
    }
    
    //arr has x , pos
    if pos != -1 {
        ret = append(ret, arr[pos])
        l = pos - 1
        r = pos + 1
        k--
    }else{
        if math.Abs(float64(arr[l] - x)) <= math.Abs(float64(arr[r] - x)){
            ret = append(ret,arr[l])
            l--
        }else{
            ret = append(ret,arr[r])
            r++
        }
        k--
    }
    
    for k > 0{
        if l >= 0 && r < len(arr){
            if math.Abs(float64(arr[l] - x)) <= math.Abs(float64(arr[r] - x)){
                ret = append([]int{arr[l]},ret...)
                l--
            }else{
                ret = append(ret, arr[r])
                r++
            }
        }else if l >= 0 {
            ret = append([]int{arr[l]},ret...)
            l--
        }else if r < len(arr){
            ret = append(ret, arr[r])
            r++
        }
        k--
    }
    return ret
}
