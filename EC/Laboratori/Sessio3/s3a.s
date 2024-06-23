    .data
# int mat1[5][6];
# TOTAL: 5*6*4 = 120 B
# log2(4) = 2
.align 2
mat1: .space 120

# char mat2[3][5];
# TOTAL: 3*5*1 = 15 B
mat2: .space 15

# long long mat3[2][2]
# TOTAL: 2*2*8 = 32 B
# log2(8) = 3
.align 3
mat3: .space 32

# int mat4[2][3] = {{2, 3, 1}, {2, 4, 3}};
# log2(4) = 2
.align 2
mat4:   2,3,1,
        2,4,3