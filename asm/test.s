.name "tester"
.comment "i'm tester champion"


#hello
test_label:
double_label:		sti r1, %:live, %1 #comment
		and r1, %0, r1 ;comment2

go_5_bytes_back:
		live %1
		zjmp %:go_5_bytes_back
.statement "not statement"
