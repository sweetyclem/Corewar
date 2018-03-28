.name "Our own champion"
.comment "We can scare a small squirrel !"

sti	r1, %:live, %1
sti	r1, %:live, %2
ld	%1, r5
live:	live %4
		zjmp %:live