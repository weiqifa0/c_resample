make:
	gcc -D _GNU_SOURCE  noise_suppression.c main_noise.c -o main_noise -lm -std=c99
	gcc main_resample.c -o main_resample

clean:
	rm *.o main_resample main_noise a.out