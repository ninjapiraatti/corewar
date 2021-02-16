.name "zork"
.comment "just a basic living prog"

l2:	st	r3,264
	and	r1,%0,r1
live:	live	%1
	zjmp	%:live
