package player;

import net.*;
import scotlandyard.*;
import java.lang.reflect.Field;
import java.io.IOException;
import java.util.*;


public class AlphaBetaPurning implements Player {
    protected List<Colour> players;
    protected List<Integer> occloc;
    protected ScotlandYardGraph graph;
    protected List<PlayerData> playerdatas = null;

    public AlphaBetaPurning(ScotlandYardView view, String graphFilename) {
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

    private Integer AlphaBeta(Move move, double alpha, double beta, Boolean maximizingPlayer, PlayerData MrX){
        List<Move> validmoves = new ArrayList<>();
        PlayerData NewMrX = null;
        if(move instanceof MoveTicket) {
            NewMrX = new PlayerData(MrX.getPlayer(),MrX.getColour(),((MoveTicket) move).target, MrX.getTickets());
            NewMrX.removeTicket(((MoveTicket) move).ticket);
            validmoves = validmoves(NewMrX, graph);
            if(validmoves.size() == 0) return AITest.weight(graph, move, occloc);
        }
        else if(move instanceof MoveDouble) {
            NewMrX = new PlayerData(MrX.getPlayer(),MrX.getColour(),((MoveDouble) move).move2.target, MrX.getTickets());
            NewMrX.removeTicket(((MoveDouble) move).move1.ticket);
            NewMrX.removeTicket(((MoveDouble) move).move2.ticket);
            validmoves = validmoves(NewMrX, graph);
            if(validmoves.size() == 0) return AITest.weight(graph, move, occloc);
        }

        if(maximizingPlayer){
            double var = Double.NEGATIVE_INFINITY;
            for(Move move1: validmoves){
                if(var < AlphaBeta(move, alpha, beta, false, NewMrX)) var = AlphaBeta(move1, alpha, beta, false, NewMrX);
                if(alpha < var) alpha = var;
                if(beta <= alpha) break;
            }
            return (int) var;
        }
        else {
            double var2 = Double.POSITIVE_INFINITY;
            for(Move move2: validmoves){
                if(var2 > AlphaBeta(move2, alpha, beta, true, NewMrX)) var2 = AlphaBeta(move2, alpha, beta, true, NewMrX);
                if(beta > var2) beta = var2;
                if(beta <= alpha) break;
            }
            return (int) var2;
        }
    }

    private List<Move> validmoves(PlayerData Player, ScotlandYardGraph Graph){
        List<Move> possiblemoves = Graph.generateMoves(Colour.Black, Player.getLocation());
        List<Move> validmoves = new ArrayList<>();
        for(Move temp: possiblemoves){
            if(Player.hasTickets(temp)) validmoves.add(temp);
        }
        return validmoves;
    }

    private Move bestMove(List<Move> moves){
        List<Integer> Results = new ArrayList<>();
        for(Move move: moves){
            //TODO Reflection
            Results.add(AlphaBeta(move,Double.NEGATIVE_INFINITY,Double.POSITIVE_INFINITY,true,getplayer(Colour.Black)));
        }
        return moves.get(Results.indexOf(AITest.getMax(Results)));
    }

    private PlayerData getplayer(Colour colour){
        for(PlayerData Player: playerdatas){
            if(Player.getColour() == colour)
                return Player;
        }
        return null;
    }
}
