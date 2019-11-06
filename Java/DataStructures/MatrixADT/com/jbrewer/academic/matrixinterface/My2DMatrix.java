package com.jbrewer.academic.matrixinterface;

public class My2DMatrix implements Matrix {
    
    private final int R;
    private final int C;
    private final int[][] data;
        
    My2DMatrix(int x, int y){
        this.R = x;
        this.C = y;
            
        this.data = new int[R][C];
    }
    
    My2DMatrix(int[][] matrix){
        this.R = matrix.length;
        if(this.R == 0){
            this.C = 0;
            this.data = null;
        }else{
            this.C = matrix[0].length;
            this.data = new int[R][C];
            for(int i = 0; i < this.R; i++)
                for(int j = 0; j < this.C; j++)
                    this.data[i][j] = matrix[i][j]; 
        }          
    }
      
    @Override
    public int getElement(int x, int y){     
        return this.data[x][y];
    }
        
    @Override
    public int getRows(){
        return this.R;
    }
       
    @Override
    public int getColumns(){
        return this.C;
    }
     
    @Override
    public My2DMatrix scale(int scalar){
        My2DMatrix matrix = new My2DMatrix(this.getRows(), this.getColumns());
        for(int i = 0; i < this.getRows(); i++)
            for(int j = 0; j < this.getColumns(); j++)
                matrix.data[i][j] = this.data[i][j] * scalar; 
        return matrix;
    }
    
    /**
     * plus method
     */
    @Override
    public My2DMatrix plus(Matrix B){
        int r = this.R;
        int c = this.C;
        if(B.getRows() != this.getRows() || B.getColumns() != this.getColumns()) 
		    throw new RuntimeException("Illegal Dimensions");
        My2DMatrix matrix = new My2DMatrix(r, c);
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                matrix.data[i][j] = this.data[i][j] + B.getElement(i,j); 
        return matrix; 
    }
    
    @Override
    public My2DMatrix minus(Matrix B){
        int r = this.R;
        int c = this.C;
        if(B.getRows() != this.getRows() || B.getColumns() != this.getColumns()) 
		    throw new RuntimeException("Illegal Dimensions");
        My2DMatrix matrix = new My2DMatrix(R, C);
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                matrix.data[i][j] = this.data[i][j] - B.getElement(i,j); 
        return matrix; 
    }
    
    @Override
    public boolean equals(Object other){
        if(other == this)
            return true;
        if(other == null)
            return false;
        if(other.getClass() != this.getClass())
            return false;
        
        My2DMatrix matrix = (My2DMatrix) other;
        if(matrix.getRows() != this.getRows() || matrix.getColumns() != this.getColumns())
            return false;
            
        for(int i = 0; i < this.R; i++)
            for(int j = 0; j < this.C; j++)
                if(this.data[i][j] != matrix.getElement(i, j))
                    return false;
        return true;
    }
    
    @Override
    public String toString(){
        String temp = "";
        for(int i = 0; i < this.R; i++){
            temp += "\n";
            for(int j = 0; j < this.C; j++)
                temp += this.data[i][j] + " ";
            }
        return temp;
    }
    
    /**
     * Entry point for matrix testing.
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        int[][] data1 = new int[0][0];
        int[][] data2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        int[][] data3 = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
        
        Matrix m1 = new My2DMatrix(data1);
        Matrix m2 = new My2DMatrix(data2);
        Matrix m3 = new My2DMatrix(data3);
        
        System.out.println("m1 --> Rows: " + m1.getRows() + " Columns: " + m1.getColumns());
        System.out.println("m2 --> Rows: " + m2.getRows() + " Columns: " + m2.getColumns());
        System.out.println("m3 --> Rows: " + m3.getRows() + " Columns: " + m3.getColumns());
        
        //check for reference issues
        System.out.println("m2 -->\n" + m2);
        data2[1][1] = 101;
        System.out.println("m2 -->\n" + m2);

        //test equals
        System.out.println("m1==null: " + m1.equals(null));             //false
        System.out.println("m2==null: " + m2.equals(null));             //false
        System.out.println("m3==\"MATRIX\": " + m2.equals("MATRIX"));   //false
        System.out.println("m2==m1: " + m2.equals(m1));                 //false
        System.out.println("m2==m2: " + m2.equals(m2));                 //true
        System.out.println("m2==m3: " + m2.equals(m3));                 //false
        
        //test operations (valid)
        System.out.println("2 * m2:\n" + m2.scale(2));
        System.out.println("m2 + m3:\n" + m2.plus(m3));
        System.out.println("m2 - m3:\n" + m2.minus(m3));
    
    }
}
