.name "zork"
.comment ""

l2: sti r1, %:live, %1	#inst 1 + has_opc 1 + reg 1 + addr 2 + index 2 = 6 / live est a 0000 + (15 - 0)
	and r1, %-5, r1		#inst 1 + has_opc 1 + reg 1 + dir 4 + reg 1 = 8
live: live %1           #live address = 15 / inst 1 + dir 4 = 5
zjmp %:live				#inst 1 + dir 2 = 3 / zjmp est a adresse 20, live est a ffff - (20 - 15 -1)

