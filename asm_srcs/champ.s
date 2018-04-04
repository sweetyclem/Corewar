.name "Our own champion"
.comment "We can scare a small squirrel !"

sti	r1, %:live, %1
sti	r1, %:fill, %1
sti	r1, %:beginning, %1
sti	r1, %:live, %9
sti	r1, %:live, %5
beginning: ld	%1, r5
zjmp %-200
fill:	live %1
st		r2, -114
	st		r2, -123
	st		r3, -132
	st		r4, -141
	st		r2, -150
	st		r3, -160
	st		r4, -170
	st		r2, -180
	st		r3, -190
	st		r4, -200
	st		r2, -210
	st		r3, -220
	st		r4, -230
	st		r2, -240
	st		r3, -250
	st		r4, -260
	st		r2, -270
	st		r3, -280
	st		r4, -290
	st		r2, -300
	st		r3, -310
	st		r4, -320
	st		r2, -330
	st		r3, -340
	st		r4, -350
	st		r2, -360
zjmp %:live
zjmp %:fill
fork %:fill
fork %:beginning
live:	live %4
		zjmp %:live