6/8/2020

Blackjack game works with two players. No optimizations.

Optimizations needed:
	P̶l̶a̶y̶e̶r̶ ̶c̶l̶a̶s̶s̶ ̶s̶o̶ ̶t̶h̶a̶t̶ ̶I̶ ̶d̶o̶n̶'̶t̶ ̶n̶e̶e̶d̶ ̶t̶o̶ ̶c̶r̶e̶a̶t̶e̶ ̶5̶ ̶v̶i̶e̶w̶s̶,̶ ̶5̶ ̶s̶c̶e̶n̶e̶s̶,̶ ̶i̶n̶d̶i̶c̶e̶s̶,̶ ̶e̶t̶c̶ ̶f̶o̶r̶ ̶t̶h̶e̶m̶ ̶e̶a̶c̶h̶ ̶t̶i̶m̶e̶.̶	
	B̶u̶t̶t̶o̶n̶s̶ ̶s̶t̶i̶l̶l̶ ̶w̶o̶r̶k̶ ̶f̶o̶r̶ ̶s̶o̶m̶e̶ ̶r̶e̶a̶s̶o̶n̶ ̶a̶f̶t̶e̶r̶ ̶t̶h̶e̶ ̶g̶a̶m̶e̶ ̶i̶s̶ ̶o̶v̶e̶r̶.̶.̶.̶	
	Create a game w more than 2 players
̶	C̶r̶e̶a̶t̶e̶ ̶a̶ ̶g̶a̶m̶e̶ ̶w̶ ̶m̶o̶n̶e̶y̶/̶p̶o̶i̶n̶t̶s̶ ̶i̶n̶v̶o̶l̶v̶e̶d̶	
	Cover the cards w something so that one player can't see the other player's cards

AI w/ Machine Learning (Thank you TA for pointing these out)
	
- Need more nodes to differentiate between the player and AI or else it cannot optimize for itself. 
- Need to get rid of biases 1 ( pointless )
- Need a weight for every node 1 for every node 2 which would be 104*30
- Consider sparsely connecting nodes, instead of dense
- Consider ReLu instead of Sigmoid as the function
- Consider alternate solutions for the learning process
- Probably should play the AI against the Simple AI, since it would take *many* iterations