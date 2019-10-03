
func dfs(img *[][]int, sr int, sc int, origin int , newColor int ){
    image := *(img)
        
    if len(image) == 0 || len(image[0]) == 0 || newColor == origin{
        return
    }
    
    m := len(image)
    n := len(image[0])
    image[sr][sc] = newColor
    op1 := []int{1,-1,0,0}
    op2 := []int{0,0,-1,1}
    
    for c := 0; c < 4; c++ {
        x := op1[c] + sr 
        y := op2[c] + sc    
        if (x >=0 && x < m && y >=0 && y < n && image[x][y] == origin){
            image[x][y] = newColor
            dfs(img,x,y,origin,newColor)
        }    
    }
}

func floodFill(image [][]int, sr int, sc int, newColor int) [][]int {
    dfs(&image,sr,sc, image[sr][sc], newColor)
    return image
}
