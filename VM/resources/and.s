.name "andtest"
.comment "Testing and"


l2:	and	3,3,r1
	live	%-1
xor	r1, r2, r3
	zjmp %100
fork	%200
