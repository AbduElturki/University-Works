package player;

import net.*;
import scotlandyard.*;

import java.io.IOException;
import java.lang.reflect.Field;
import java.util.*;

public class MinMax implements Player {
    protected List<Colour> players;
    protected List<Integer> occloc;
    protected ScotlandYardGraph graph;
    protected List<PlayerData> playerdatas = null;




    private Integer worst2ndmove(Move move,ScotlandYardGraph Graph){
        Integer Location = 0;
        //TODO Reflection
        PlayerData Temp = getplayer(Colour.Black);
        if(move instanceof MoveTicket){
            Location = ((MoveTicket) move).target;
            Temp.removeTicket(((MoveTicket) move).ticket);
        }
        else if (move instanceof MoveDouble){
            Location = ((MoveDouble) move).move2.target;
            Temp.removeTicket(((MoveDouble) move).move1.ticket);
            Temp.removeTicket(((MoveDouble) move).move2.ticket);
        }
        List<Move> possiblemoves = Graph.generateMoves(Colour.Black, Location);
        List<Move> validmoves = new ArrayList<>();
        for(Move temp: possiblemoves){
            if(Temp.hasTickets(temp)) validmoves.add(temp);
        }
        List<Integer> results = new ArrayList<>();
        for(Move temp: validmoves){
            results.add(AITest.weight(graph,temp,occloc));
        }
        return getMin(results);
    }

    private PlayerData getplayer(Colour colour){
        for(PlayerData Player: playerdatas){
            if(Player.getColour() == colour)
                return Player;
        }
        return null;
    }

    private Integer getMin(List<Integer> inputArray){
        Integer minValue = inputArray.get(0);
        for(Integer value : inputArray){
            if(value < minValue){
                minValue = value;
            }
        }
        return minValue;
    }

    private Move bestMove(List<Move> validmoves){
        List<Integer> results = new ArrayList<>();
        for(Move move: validmoves){
            results.add(worst2ndmove(move, graph));
        }
        return validmoves.get(results.indexOf(AITest.getMax(results)));
    }

    public MinMax(ScotlandYardView view, String graphFilename) {
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

        try {
            Field playerListField=ScotlandYard.class.getDeclaredField("players");
            playerListField.setAccessible(true);
            playerdatas= new ArrayList<>((List<PlayerData>)playerListField.get(view));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public void notify(int location, List<Move> moves, Integer token, Receiver receiver) {
        //TODO: Some clever AI here ...
        System.out.println("Playing the best move ( ͡° ͜ʖ ͡°) : " + bestMove(moves));
        receiver.playMove(bestMove(moves), token);
    }
}
