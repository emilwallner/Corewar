.name "skynet"
.comment "j'aime les chats"

setlive:
	st r1, 7
	ld %323, r1
	ld %0, r2
	st r2, :setlive
	sti r2, %:setlive, %1
	sti r1, %:wall, %1
	sti r1, %:wall, %1
	sti r1, %:wall2, %1
	sti r1, %:live, %1
	sti r1, %:live1, %1
	sti r1, %:loop, %1

wall_prep:
	ld		%0, r2
	ld		%0, r16

fork %:wall

live1:
	live	%12345

fork %:wall2
zjmp %:loop

wall:
	live	%12345
	st	r2, -37
	st	r2, -46
	st	r2, -55
	st	r2, -64
	st	r2, -73
	st	r2, -82
	st	r2, -91
	st	r2, -100
	st	r2, -109
	st	r2, -118
	st	r2, -127
	st	r2, -136
	st	r2, -145
	st	r2, -154
	st	r2, -163
	st	r2, -172
	st	r2, -181
	st	r2, -190
	st	r2, -199
	st	r2, -208
	st	r2, -217
	st	r2, -226
	st	r2, -235
	st	r2, -244
	st	r2, -253
	st	r2, -262
	st	r2, -271
	st	r2, -280
	st	r2, -289
	st	r2, -298
	st	r2, -307
	st	r2, -316
	st	r2, -325
	st	r2, -334
	st	r2, -343
	st	r2, -352
	st	r2, -361
	st	r2, -370
	st	r2, -379
	st	r2, -388
	st	r2, -397
	st	r2, -406
	st	r2, -415
	st	r2, -424
	st	r2, -433
	st	r2, -442
	st	r2, -451
	st	r2, -460
	st	r2, -469
	st	r2, -478
	st	r2, -487
	st	r2, -496
	st	r2, -505
	st	r2, -511
	zjmp %:wall

loop:
	live %12345
	fork %:live
zjmp %:loop

live:
	live %12345
zjmp %:live

wall2:
	live %12345
	st	r2, 273
	st	r2, 272
	st	r2, 271
	st	r2, 270
	st	r2, 269
	st	r2, 268
	st	r2, 267
	st	r2, 266
	st	r2, 265
	st	r2, 264
	st	r2, 263
	st	r2, 262
	st	r2, 261
	st	r2, 260
	st	r2, 259
	st	r2, 258
	st	r2, 257
	st	r2, 256
	st	r2, 255
	st	r2, 254
	st	r2, 253
	st	r2, 252
	st	r2, 251
	st	r2, 250
	st	r2, 249
	st	r2, 248
	st	r2, 247
	st	r2, 246
	st	r2, 245
	st	r2, 244
	st	r2, 243
	st	r2, 242
	st	r2, 241
	st	r2, 240
	st	r2, 239
	st	r2, 238
	st	r2, 237
	st	r2, 236
	st	r2, 235
	st	r2, 234
	st	r2, 233
	st	r2, 232
	st	r2, 231
	st	r2, 230
	st	r2, 229
	st	r2, 228
	st	r2, 227
	st	r2, 226
	st	r2, 225
	st	r2, 223
	st	r2, 222
	st	r2, 221
	st	r2, 220
	zjmp %:wall2
