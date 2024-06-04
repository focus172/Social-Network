hello: network.o user.o social_network.o post.o
	g++ $^ -o $@

%.o: %.cpp
	g++ -c $< -o $@

clean:
	rm *.o output