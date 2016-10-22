package player;

import graph.Edge;
import graph.Graph;
import graph.GraphReader;
import graph.Node;
import jdk.nashorn.internal.runtime.Undefined;
import scotlandyard.*;

import java.io.IOException;
import java.util.*;

/**
 * The RandomPlayer class is an example of a very simple AI that
 * makes a random move from the given set of moves. Since the
 * RandomPlayer implements Player, the only required method is
 * notify(), which takes the location of the player and the
 * list of valid moves. The return value is the desired move,
 * which must be one from the list.
 */





    public class AITest implements Player{
    protected List<Colour> players;
    protected List<Integer> occloc;
    protected ScotlandYardGraph graph;

    protected Graph<Integer,Integer> graph_test;

    public void translate(ScotlandYardGraph  to_trans){
        ArrayList<Edge<Integer,Transport>> edge_to_add = (ArrayList<Edge<Integer,Transport>>) to_trans.getEdges();
        ArrayList<Node<Integer>>  node_to_add = (ArrayList<Node<Integer>>) to_trans.getNodes();
        for(Node<Integer> temp: node_to_add){
            graph_test.add(temp);
        }
        for(Edge<Integer,Transport> temp1: edge_to_add){
            Edge<Integer,Integer> adding = new Edge<>(temp1.getSource(),temp1.getTarget(),1);
            graph_test.add(adding);
        }
        //return null;
    }

    public static Integer getMax(List<Integer> inputArray){
        int maxIndex = 0;
        for (int i = 1; i < inputArray.size(); i++){
            int newnumber = inputArray.get(i);
            if ((newnumber > inputArray.get(maxIndex))) maxIndex = i;
        }
        return maxIndex;
    }


    public static Integer weight (ScotlandYardGraph graph, Move temp, List<Integer> occloc){
        int result = 0;
        ArrayList<Edge<Integer,Transport>> weight = new ArrayList<>();
        if(temp instanceof MoveTicket) {
            weight =  (ArrayList<Edge<Integer, Transport>>) graph.getEdgesFrom(graph.getNode(((MoveTicket) temp).target));
            for (Edge<Integer, Transport> temp1 : weight) {
                if (!occloc.contains(temp1.getTarget())) {
                    result++;
                }
            }
        } else if(temp instanceof MoveDouble){
            weight = (ArrayList<Edge<Integer,Transport>>) graph.getEdgesFrom((graph.getNode(((MoveDouble) temp).move2.target)));
            for (Edge<Integer, Transport> temp1 : weight) {
                if (!occloc.contains(temp1.getTarget())) {
                    result++;
                }
            }
        }
        return result;
    }


    /* converts all the edges into*/

   // public Graph tanslator(){
   //     return null;//}

    public AITest (ScotlandYardView view, String graphFilename) {
        //TODO: A better AI makes use of `view` and `graphFilename`.
        this.players = view.getPlayers();
        List<Integer> test = new ArrayList<Integer>();
        for(Colour tempx: players){
            if(!(tempx.equals(Colour.Black))) test.add(view.getPlayerLocation(tempx));
        }
        graph = new ScotlandYardGraph();
        ScotlandYardGraphReader reader = new ScotlandYardGraphReader();
        try {
            graph = reader.readGraph(graphFilename);
        } catch (IOException e) {
            e.printStackTrace();
        }
        for(Colour temp: players){
            if(!temp.equals(Colour.Black)) occloc.add(view.getPlayerLocation(temp));
        }
    }

    private Move bestMove(List<Move> ValidMoves){
        ArrayList<Integer> results = new ArrayList<>();
        for(Move move : ValidMoves){
            results.add(weight(graph,move,occloc));
        }
        return ValidMoves.get(results.indexOf(getMax(results)));
    }

    @Override
    public void notify(int location, List<Move> moves, Integer token, Receiver receiver) {
        //TODO: Some clever AI here ...
        Move bestmove = bestMove(moves);
        System.out.println("Playing the best move ( ͡° ͜ʖ ͡°) : " + bestmove);
        receiver.playMove(bestmove, token);
    }
}
