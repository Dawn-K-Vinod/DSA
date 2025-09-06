# 🟢 **Algorithm: Compact Matrix Addition** 

---

### **Step-1: Start the program**
**Initialize** the environment and prepare for user interaction by launching the main function.

---

### **Step-2: Input Matrix Dimensions and Declaration**
**Prompt** the user for the number of rows and columns.  
**Declare** two 2D arrays (`matrix1` and `matrix2`) with the specified size.

---

### **Step-3: Read Sparse Matrices**
**For each matrix:**  
- Request the user to enter the elements row by row.  
- **Store** the input values in the corresponding array.

---

### **Step-4: Display Sparse Matrices**
**Print** both matrices in a formatted manner to visually confirm the input.

---

### **Step-5: Convert to Compact (Triplet) Representation**
**For each matrix:**  
- **Scan** all elements.  
- **For each non-zero element:**  
  - Record a triplet: `(row, column, value)` in a compact matrix.  
- The **first row** of the compact matrix holds:  
  - Number of rows  
  - Number of columns  
  - Count of non-zero elements

---

### **Step-6: Display Compact Matrices**
**Print** the compact form of both matrices, showing only the non-zero elements and their positions.

---

### **Step-7: Initialize Result Compact Matrix**
**Declare** a result compact matrix for storing the sum.  
**Set** its first row with total rows and columns.  
**Initialize** counters for iterating and merging.

---

### **Step-8: Merge Compact Matrices (Addition)**
- **Iterate** through both compact matrices using pointers.
- **Compare** current element positions:
  - If `compact1` index is smaller, copy its element.
  - If `compact2` index is smaller, copy its element.
  - If both indices are equal, **add values** and copy to result.
- **Copy** any remaining elements from either matrix to result.
- **Maintain** sorted order in the result.

---

### **Step-9: Update Count & Display Result**
**Update** the first row of the result matrix with the new non-zero count.  
**Print** the resultant compact matrix showing the sum.

---

### **Step-10: Transpose and Display Result**
**Create** a transpose of the result compact matrix by swapping rows and columns.  
**Display** the transposed matrix for alternate view.

---

### **Step-11: End the Program**
**Terminate** execution and release any resources used.

---
