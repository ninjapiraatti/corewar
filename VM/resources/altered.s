.name " maxidef "
.comment " module de defense"

slide1: live %-1
	init:	ld %57672703,r3
		ld %0,r5

defm:	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
deflv:	live %-1
	zjmp %:defm


