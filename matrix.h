//
// Created by מוחמד עבידאת on 27/08/2021.
//

#ifndef DATA_STRUCTURE_MATRIX_H
#define DATA_STRUCTURE_MATRIX_H



/**
 * basic matrix MxN
 */


class matrix{
protected:
    int row;
    int column;
    vector<vector<int>> mat;
public:
    matrix(int x=3):matrix(x,x){}

    matrix(int x,int y): row(x),column(y),mat(vector<vector<int>> (row)){
         for ( int i = 0 ; i < row ; i++ )
             mat[i].resize(column);
    }
    matrix& operator=(const matrix& oth){
        if(oth.mat == this->mat){
            return *this;
        }
        if(row != oth.row || column != oth.column){
            error("wrong operator Plus");
            throw error_throw("wrong operator Plus");
        }
        for(int i =0 ;i<row;i++){
            for(int j=0;j<column;j++)
                mat[i][j]=oth.mat[i][j];
        }
        return *this;
    }
  vector<int>& operator[](int x){
            return mat[x];
    }
    vector<vector<int>>& get_matrix(){
        return mat;
    }
    const vector<int>& operator[](int x)const {
        return mat[x];
    }


        matrix& operator+=(const matrix& other2){
        if(other2.row != row || other2.column != column){
            error("wrong operator Plus");
        }
        for(int i =0 ;i<other2.row;i++){
            for(int j=0;j<other2.column;j++)
                mat[i][j] =other2.mat[i][j]+mat[i][j];
        }
        return *this;
    }

    matrix& operator-=(const matrix& other2){
        if(other2.row != row || other2.column != column){
            error("wrong operator Plus");
        }
        for(int i =0 ;i<other2.row;i++){
            for(int j=0;j<other2.column;j++)
                mat[i][j] =mat[i][j]-other2.mat[i][j];
        }
        return *this;
    }

    int max_num(){
        int temp = mat[0][0];
        for(int i =0 ;i<row;i++){
            for(int j=0;j<column;j++)
                if(mat[i][j] > temp)
                    temp = mat[i][j];
        }
        return temp;
    }

    int get_row(){
        return row;
    }
    int get_col(){
        return column;
    }

    friend std::ostream &operator<<(std::ostream &,  matrix &);
    matrix operator*(const int s);
    friend  matrix operator+(const matrix& other1,const matrix& other2);
    friend  matrix operator-(const matrix& other1,const matrix& other2);
    friend  matrix operator*(const matrix& other1,const matrix& other2);


};



ostream& operator<<(ostream& os,matrix& a) {
    //for(int i =)
    int max = (int) (to_string(a.max_num())).length();
    //string a = " ";
    os << string(UNDERLINE) * a.column << endl;
    for (int i = 0; i < a.row; i++) {
        for (int j = 0; j < a.column; j++) {
            os << u8"║" << a.mat[i][j] << u8"║";
        }
        os << endl;
    }
    return os;
}

matrix operator+(const matrix& other1,const matrix& other2){
    if(other2.row != other1.row || other2.column != other1.column){
        error("wrong operator Plus");
        throw error_throw("wrong operator Plus");
    }
    matrix temp (other1.row,other1.column);
    for(int i =0 ;i<other2.row;i++){
        for(int j=0;j<other2.column;j++)
            temp[i][j] =other2.mat[i][j]+other1.mat[i][j];
    }
    return temp;
}
matrix operator-(const matrix& other1,const matrix& other2){
    if(other2.row != other1.row || other2.column != other1.column){
        error("wrong operator Plus");
        throw error_throw("wrong operator Plus");
    }
    matrix temp (other1.row,other1.column);
    for(int i =0 ;i<other2.row;i++){
        for(int j=0;j<other2.column;j++)
            temp[i][j] =other2.mat[i][j]+other1.mat[i][j];
    }
    return temp;
}
matrix operator*(const matrix& other1,const matrix& other2){
    if(other2.row != other1.column){
        error("Multiplication is not defined");
        throw error_throw("Multiplication is not defined");
    }
    int sum = 0;
    matrix temp (other1.row, other2.column);

    for(int i =0 ;i <other1.row;i ++) {
        for(int k = 0 ; k < other2.column;k++){
            for (int j = 0; j < other2.row; j++) {
                sum += other1[i][j] * other2[j][k];
            }
            temp[i][k] = sum;
            sum=0;
        }
    }
    return temp;
}
matrix matrix::operator*(const int s) {
    matrix temp (row,column);
    for(int i =0 ;i <row;i ++) {
        for (int j = 0; j < column; j++) {
            temp[i][j] = s * mat[i][j];
        }
    }
    return temp;}




class ZeroMatrix : public matrix{
public:

    //ZeroMatrix(int x = 3): matrix(x){}
    ZeroMatrix(int x = 3,int y =3): matrix(x,y){}

    const vector<int>& operator[](int x){
        return mat[x];
    }

    const vector<int>& operator[](int x)const {
        return mat[x];
    }


    friend matrix operator+(const ZeroMatrix& other1,const matrix& other2);
    friend matrix operator-(const ZeroMatrix& other1,const matrix& other2);
    friend matrix operator*(const ZeroMatrix& other1, matrix& other2);

};

matrix operator+(const ZeroMatrix& other1,const matrix& other2){
    return other2;
}
matrix operator-(const ZeroMatrix& other1,const matrix& other2){
    return other2;
}
matrix operator*(const ZeroMatrix& other1, matrix& other2){
    if(other2.get_row() != other1.column){
        error("Multiplication is not defined");
        throw error_throw("Multiplication is not defined");
    }
    return other1;
}
#endif //DATA_STRUCTURE_MATRIX_H
