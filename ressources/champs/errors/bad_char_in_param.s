.name    "sebc"
.comment "sebc"

	st	r1, :l1
	ld	%4, r3c #bad char
l1:	live	%1( #bad char
	ld	%:l1, r2
l3:	ldi	%:l2, r2, r4
	sti	r4, %:l2, r2
	add	r2, r3, r2
live:	zjmp	%:l1 + 2 #bad char
	zjmp	%:l3
l2:
