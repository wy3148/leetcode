// 638. Shopping Offers
// DescriptionHintsSubmissionsDiscussSolution
// In LeetCode Store, there are some kinds of items to sell. Each item has a price.

// However, there are some special offers, and a special offer consists of one or more different kinds of items with a sale price.

// You are given the each item's price, a set of special offers, and the number we need to buy for each item. The job is to output the lowest price you have to pay for exactly certain items as given, where you could make optimal use of the special offers.

// Each special offer is represented in the form of an array, the last number represents the price you need to pay for this special offer, other numbers represents how many specific items you could get if you buy this offer.

// You could use any of special offers as many times as you want.

// Example 1:
// Input: [2,5], [[3,0,5],[1,2,10]], [3,2]
// Output: 14
// Explanation:
// There are two kinds of items, A and B. Their prices are $2 and $5 respectively.
// In special offer 1, you can pay $5 for 3A and 0B
// In special offer 2, you can pay $10 for 1A and 2B.
// You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), and $4 for 2A.
// Example 2:
// Input: [2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1]
// Output: 11
// Explanation:
// The price of A is $2, and $3 for B, $4 for C.
// You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C.
// You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special offer #1), and $3 for 1B, $4 for 1C.
// You cannot add more items, though only $9 for 2A ,2B and 1C.
// Note:
// There are at most 6 kinds of items, 100 special offers.
// For each item, you need to buy at most 6 of them.
// You are not allowed to buy more items than you want, even if that would lower the overall price.

var ans int

func isValid(offer []int, need []int) bool {
	for i := 0; i < len(offer)-1; i++ {
		if offer[i] > need[i] {
			return false
		}
	}
	return true
}

//dfs 计算可以选择的offer
/// go语言的特性slice 本身不是深拷贝 是指针拷贝，但是传递掉一下递归函数的时候
//需要注意值的变化，我们可以point来表示计算，类似c++的reference
//那么这样就需要backtracking

func dfs(price []int, special [][]int, needs *[]int, total *int) {

	all := true
	for _, v := range *needs {
		if v != 0 {
			all = false
			break
		}
	}

	if all {
		if ans > (*total) {
			ans = (*total)
		}
		return
	}

	found := false
	for _, offer := range special {
		valid := isValid(offer, (*needs))
		if valid {
			found = true
			(*total) += offer[len(offer)-1]
			for i := 0; i < len(offer)-1; i++ {
				(*needs)[i] -= offer[i]
			}
			dfs(price, special, needs, total)
			//backtrack
			(*total) -= offer[len(offer)-1]
			for i := 0; i < len(offer)-1; i++ {
				(*needs)[i] += offer[i]
			}
		}
	}

	if !found {

		//拷贝total的值，如果直接修改total的值那么需要backtrack 就不是很方便
		//所以声明一个额外变量cost来记录当前的total + 然后计算剩余的cost
		cost := (*total)
		for i := 0; i < len(*needs); i++ {
			if (*needs)[i] > 0 {
				cost += price[i] * (*needs)[i]
			}
		}
		if ans > cost {
			ans = cost
		}
	}
}

func shoppingOffers(price []int, special [][]int, needs []int) int {

	//firstly calculate cost without offer
	for i := 0; i < len(needs); i++ {
		ans += price[i] * needs[i]
	}

	total := 0
	dfs(price, special, &needs, &total)
	return ans
}
