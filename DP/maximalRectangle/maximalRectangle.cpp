/**
 * @file maximalRectangle.cpp
 * @author your name (Frand@domain.com)
 * @brief LeetCode 85 the maximum rectangle of the matrix
 * @version 0.1
 * @date 2021-06-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<iostream>
#include<vector>
#include<cstdlib>
#include<cctype>
using namespace std;


int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
    if(matrixSize == 0){
        return 0;
    }
    int row = matrixSize;
    int col = matrixColSize[0];
    int tmp[row][col];
    int tmpSum = 0;
    int ret = 0;
    for(int i = 0; i < row; i++){
        tmpSum = 0;
        for(int j=0; j<col; j++){
            if(matrix[i][j] == '1'){ // 统计前面连续1个数
                tmp[i][j] = ++tmpSum;
                ret = fmax(tmp[i][j], ret); // 统计每个单行场景下最大值
            }else{
                tmp[i][j] = 0;
                tmpSum = 0;
            }
        }
    }
    int tmpMin = 0;
    for(int i = 1; i < row; i++){
        for(int j=0; j<col; j++){
            if(tmp[i][j] == 0 ){
                continue;
            }
            tmpMin = tmp[i][j];
            for(int k=i-1; k>=0; k--){
                if(tmp[k][j] == 0 ){
                    break;
                }
                tmpMin = fmin(tmpMin, tmp[k][j]); //一层一层向上统计，每此递增一层时最小层宽 * 高度
                ret = fmax(ret, tmpMin * (i - k + 1));
            }
        }
    }

    return ret;
}

// 作者：yuanxin-xie
// 链接：https://leetcode-cn.com/problems/maximal-rectangle/solution/qian-zhui-bao-li-shi-jian-chao-guo-973-b-g3ek/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。