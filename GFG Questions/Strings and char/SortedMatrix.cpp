//Taking the first element as max and comparing every other element of the matrix to that element to obtain the maximum element and also swapping the elements whenever an element>Max is found -----------TLE
class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        int maxIndex=0;
        int max=INT_MIN;
        int rowIndex=N-1;
        int colIndex=N-1;
        bool swapped=false;
        for(int row=0;row<N;row++)
        {
            for(int col=0;col<N;col++)
            {
                
                int max=Mat[row][col];
                for(int i=0;i<N;i++)
                {
                    for(int j=0;j<N;j++)
                    {
                        if(Mat[i][j]>max)
                        {
                            swap(Mat[row][col],Mat[i][j]);
                            max=Mat[i][j];
                            swapped=true;
                        }
                    }
                }
                if(swapped==false) return Mat; //if the matrix is sorted initially
            }
        }
        return Mat;
    }
};