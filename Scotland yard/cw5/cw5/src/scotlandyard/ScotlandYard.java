package scotlandyard;

import graph.Edge;
import java.util.*;

/**
 * A class to perform all of the game logic.
 */

public class ScotlandYard implements ScotlandYardView, Receiver {

    protected MapQueue<Integer, Token> queue;
    protected Integer gameId;
    protected Random random;
    protected List<Boolean> rounds;
    protected Integer numberOfDectivces;
    protected ScotlandYardGraph graph;
    protected List<PlayerData> players;
    protected PlayerData currentPlayer;
    protected int currentround;
    protected int mrXlastknownlocation = 0;
    protected List<Spectator> spectators;

    /**
     * Constructs a new ScotlandYard object. This is used to perform all of the game logic.
     *
     * @param numberOfDetectives the number of detectives in the game.
     * @param rounds the List of booleans determining at which rounds Mr X is visible.
     * @param graph the graph used to represent the board.
     * @param queue the Queue used to put pending moves onto.
     * @param gameId the id of this game.
     */
    public ScotlandYard(Integer numberOfDetectives, List<Boolean> rounds, ScotlandYardGraph graph, MapQueue<Integer, Token> queue, Integer gameId) {
        this.queue = queue;
        this.gameId = gameId;
        this.random = new Random();
        //DONE
        this.rounds = rounds;
        this.graph = graph;
        this.numberOfDectivces = numberOfDetectives;
        this.players = new ArrayList<>();
        this.spectators = new ArrayList<>();
    }

    /**
     * Starts playing the game.
     */
    public void startRound() {
        if (isReady() && !isGameOver()) {
            turn();
        }
    }

    /**
     * Notifies a player when it is their turn to play.
     */
    public void turn() {
        Integer token = getSecretToken();
        queue.put(gameId, new Token(token, getCurrentPlayer(), System.currentTimeMillis()));
        notifyPlayer(getCurrentPlayer(), token);
    }

    /**
     * Plays a move sent from a player.
     *
     * @param move the move chosen by the player.
     * @param token the secret token which makes sure the correct player is making the move.
     */
    public void playMove(Move move, Integer token) {
        Token secretToken = queue.get(gameId);
        if (secretToken != null && token.equals(secretToken.getToken())) {
            queue.remove(gameId);
            play(move);
            nextPlayer();
            startRound();
        }
    }

    /**
     * Returns a random integer. This is used to make sure the correct player
     * plays the move.
     * @return a random integer.
     */
    private Integer getSecretToken() {
        return random.nextInt();
    }

    /**
     * Notifies a player with the correct list of valid moves.
     *
     * @param colour the colour of the player to be notified.
     * @param token the secret token for the move.
     */
    private void notifyPlayer(Colour colour, Integer token) {
        for(PlayerData temp : players) {
            if (temp.getColour() == colour) {
                temp.getPlayer().notify(temp.getLocation(), validMoves(temp.getColour()),token, this);
            }
        }
    }

    /**
     * Passes priority onto the next player whose turn it is to play.
     */
    protected void nextPlayer() {
        for (int i = 0; i < players.size(); i++){
            if(players.get(i).getColour() == currentPlayer.getColour()){
                if(players.size()-1 == i){
                    currentPlayer = players.get(0);
                    break;
                }
                else currentPlayer = players.get(i+1);
                break;
            }
        }
    }

    /**
     * Allows the game to play a given move.
     *
     * @param move the move that is to be played.
     */
    protected void play(Move move) {
        if (move instanceof MoveTicket) play((MoveTicket) move);
        else if (move instanceof MoveDouble) play((MoveDouble) move);
        else if (move instanceof MovePass) play((MovePass) move);
    }

    /**
     * Plays a MoveTicket.
     *
     * @param move the MoveTicket to play.
     */
    protected void play(MoveTicket move) {
        MoveTicket newMove = move;
        PlayerData player = getPlayer(move.colour);
        player.removeTicket(move.ticket);
        player.setLocation(move.target);
        if(move.colour.equals(Colour.Black)) {
            increment();
            newMove = MoveTicket.instance(Colour.Black, move.ticket, mrXlastknownlocation);
        }
        else {
            PlayerData mrX = this.getPlayer(Colour.Black);
            mrX.addTicket(move.ticket);
        }
        notifySpectators(newMove);

    }

    protected PlayerData getPlayer(Colour colour){
        for(PlayerData player : players){
            if(player.getColour() == colour) return player;
        }
        return null;
    }

    /**
     * Plays a MoveDouble.
     *
     * @param move the MoveDouble to play.
     */
    protected void play(MoveDouble move) {

        notifySpectators((Move)move);
        //Play the first move
        play(move.move1);

        //Play the second move
        play(move.move2);

        PlayerData player = getPlayer(((Move) move).colour);
        player.removeTicket(Ticket.Double);

    }

    /**
     * Plays a MovePass.
     *
     * @param move the MovePass to play.
     */
    protected void play(MovePass move) {
        for(PlayerData temp : players){
            if(temp.getColour() == move.colour){
                temp.setLocation(temp.getLocation());
            }
        }
        notifySpectators((Move)move);
    }

    /**
     * Returns the list of valid moves for a given player.
     *
     * @param player the player whose moves we want to see.
     * @return the list of valid moves for a given player.
     */
    public List<Move> validMoves(Colour player) {
        ArrayList<Integer> occloc  = new ArrayList<Integer>();
        for(PlayerData temp: players){
            if(!temp.getColour().equals(Colour.Black)){
                occloc.add(temp.getLocation());
            }
        }
        ArrayList<Move> moves = new ArrayList<Move>();
        for (PlayerData temp : players) {
            if (temp.getColour() == player) {
                List<Edge<Integer, Transport>> edges = graph.getEdgesFrom(graph.getNode(temp.getLocation()));
                for (Edge<Integer, Transport> edge : edges) {
                    Ticket tickettemp = Ticket.fromTransport(edge.getData());
                    MoveTicket tempmove = MoveTicket.instance(temp.getColour(), tickettemp, edge.getTarget().getIndex());
                    if(!temp.getColour().equals(Colour.Black)){
                        if(temp.hasTickets(tempmove) && !occloc.contains(edge.getTarget().getIndex())){moves.add(tempmove);}

                    }else {
                        Map<Ticket,Integer> ticketMap = temp.getTickets();
                        MoveTicket tempsecret = MoveTicket.instance(temp.getColour(), Ticket.Secret, edge.getTarget().getIndex());
                        if(temp.hasTickets(tempmove) && !occloc.contains(edge.getTarget().getIndex())){
                            moves.add(tempmove);
                            if (ticketMap.get(Ticket.Secret)>0) {moves.add(tempsecret);}
                        }
                        List<Edge<Integer, Transport>> edgesdoubles = graph.getEdgesFrom(edge.getTarget());
                        ArrayList<MoveDouble> tempmoveDoubles = new ArrayList<MoveDouble>();
                        for(Edge<Integer, Transport> tempDoubledge: edgesdoubles){
                            Ticket tempmovesecond = Ticket.fromTransport(tempDoubledge.getData());
                            MoveTicket tempsecond  = MoveTicket.instance(temp.getColour(), tempmovesecond, tempDoubledge.getTarget().getIndex());
                            MoveDouble tempDouble = MoveDouble.instance(temp.getColour(), tempmove, tempsecond);
                            MoveTicket tempsecret2 = MoveTicket.instance(temp.getColour(), Ticket.Secret, tempDoubledge.getTarget().getIndex());
                            MoveDouble tempDoubleSecret = MoveDouble.instance(temp.getColour(), tempmove, tempsecret2);
                            MoveDouble tempDoubleSecret2 = MoveDouble.instance(temp.getColour(), tempsecret, tempsecond);
                            if(!occloc.contains(tempDoubledge.getTarget().getIndex())){
                                tempmoveDoubles.add(tempDouble);
                                if(ticketMap.get(Ticket.Secret)>0){
                                    tempmoveDoubles.add(tempDoubleSecret);
                                    tempmoveDoubles.add(tempDoubleSecret2);
                                }
                                MoveDouble tempDoubleSecret_2 = MoveDouble.instance(temp.getColour(), tempsecret, tempsecret2);
                                if(ticketMap.get(Ticket.Secret)>2){ tempmoveDoubles.add(tempDoubleSecret_2);}
                            }

                            for(MoveDouble tempmve: tempmoveDoubles){
                                if(temp.hasTickets(tempmve) && !occloc.contains(tempDoubledge.getSource().getIndex())){ moves.add(tempmve);}
                            }
                        }
                    }
                }
            }
        }

        if (moves.isEmpty() && !(player == Colour.Black)) {
            moves.add(MovePass.instance(player));
        }
        return moves;
    }

    /**
     * Allows spectators to join the game. They can only observe as if they
     * were a detective: only MrX's revealed locations can be seen.
     *
     * @param spectator the spectator that wants to be notified when a move is made.
     */
    public void spectate(Spectator spectator) {
        spectators.add(spectator);
    }

    public void notifySpectators(Move move){
        for(Spectator spectator: spectators){
            spectator.notify(move);
        }
    }

    /**
     * Allows players to join the game with a given starting state. When the
     * last player has joined, the game must ensure that the first player to play is Mr X.
     *
     * @param player the player that wants to be notified when he must make moves.
     * @param colour the colour of the player.
     * @param location the starting location of the player.
     * @param tickets the starting tickets for that player.
     * @return true if the player has joined successfully.
     */
    public boolean join(Player player, Colour colour, int location, Map<Ticket, Integer> tickets) {

        //Failed join
        if(player == null || colour == null || tickets == null) {return false;}

        //If MrX joins the game.
        if(colour == Colour.Black) {
            players.add(0, new PlayerData(player,colour,location,tickets));
            currentPlayer = players.get(0);
        }

        //If Detective joins the game
        else{
            players.add(new PlayerData(player,colour,location,tickets));
        }

        return true;
    }

    /**
     * A list of the colours of players who are playing the game in the initial order of play.
     * The length of this list should be the number of players that are playing,
     * the first element should be Colour.Black, since Mr X always starts.
     *
     * @return The list of players.
     */
    public List<Colour> getPlayers() {
        List<Colour> returned = new ArrayList<Colour>();
        for(PlayerData temp: players){
            returned.add(temp.getColour());
        }
        return returned;
    }

    /**
     * Returns the colours of the winning players. If Mr X it should contain a single
     * colour, else it should send the list of detective colours
     *
     * @return A set containing the colours of the winning players
     */
    public Set<Colour> getWinningPlayers() {
        Set<Colour> winngplayers = new HashSet<Colour>();

        //If MrX won returns list that contains only MrX's colour
        if(MrXwon()) winngplayers.add(getPlayers().get(0));

        //If MrX lost returns list of Detectives's colour
        if(MrXlost()){
            for(Colour temp: getPlayers()){
            if(temp == (Object) Colour.Black) continue;
                winngplayers.add(temp);
            }
        }

        //returns the list
        return winngplayers;
    }

    /**
     * The location of a player with a given colour in its last known location.
     *
     * @param colour The colour of the player whose location is requested.
     * @return The location of the player whose location is requested.
     * If Black, then this returns 0 if MrX has never been revealed,
     * otherwise returns the location of MrX in his last known location.
     * MrX is revealed in round n when {@code rounds.get(n)} is true.
     */
    public int getPlayerLocation(Colour colour) {

        PlayerData player = getPlayer(colour);
        if(player.getColour() == Colour.Black) {
            if(getRounds().get(currentround)) return player.getLocation();
            return mrXlastknownlocation;
        }
        return player.getLocation();
    }

    /**
     * The number of a particular ticket that a player with a specified colour has.
     *
     * @param colour The colour of the player whose tickets are requested.
     * @param ticket The type of tickets that is being requested.
     * @return The number of tickets of the given player.
     */
    public int getPlayerTickets(Colour colour, Ticket ticket) {

        //Looks up the player and returns their ticket.
        PlayerData player =  getPlayer(colour);
        return player.getTickets().get(ticket);
    }

    /**
     * The game is over when MrX has been found or the agents are out of
     * tickets. See the rules for other conditions.
     *
     * @return true when the game is over, false otherwise.
     */
    public boolean isGameOver() {

        //Game shouldn't be over if it isn't ready
        if(!isReady()) return false;

        //return true if the game is over, by checking if either MrX won or lost.
        return (MrXlost() || MrXwon());
    }

    /**
     * The game is over if MrX has won
     *
     * @return true if MrX won.
     */
    private boolean MrXwon(){

        if(rounds.size() - 1 <= currentround && currentPlayer.getColour().equals(Colour.Black)) return true;

        //Game should be over if MrX ran out of tickets
        if(validMoves(players.get(0).getColour()).size() == 1 &&
                validMoves(players.get(0).getColour()).get(0) == MovePass.instance(players.get(0).getColour())) return true;

        //Game should be over if Detectives don't have valid moves nor tickets
        int playersWhoDontHaveValidMoves = 0;
        for(PlayerData temp: players){
            if(temp.getColour() == (Object) Colour.Black) continue;
            if(validMoves(temp.getColour()).size() == 1 &&
                    validMoves(temp.getColour()).get(0) == MovePass.instance(temp.getColour())) playersWhoDontHaveValidMoves++;
        }
        if (playersWhoDontHaveValidMoves == numberOfDectivces) return true;

        //Game should be over if Mr. X is the only player that is playing.
        return (players.size() == 1 && players.get(0).getColour() == (Object) Colour.Black);

    }

    /**
     * The Game is over if MrX has lost
     *
     * @return true if MrX lost.
     */
    private boolean MrXlost(){

        //Game should be over if the Detective is the same location as Mr. X
        if(validMoves(players.get(0).getColour()).isEmpty()) return true;
        int mrXlocation = players.get(0).getLocation();
        for(PlayerData temp: players){
            if(temp.getColour() == (Object) Colour.Black) continue;
            if(temp.getLocation() == mrXlocation) return true;
        }

        return false;
    }

    /**
     * A game is ready when all the required players have joined.
     *
     * @return true when the game is ready to be played, false otherwise.
     */
    public boolean isReady() {
        return (players.size() == (numberOfDectivces+1));
    }

    /**
     * The player whose turn it is.
     *
     * @return The colour of the current player.
     */
    public Colour getCurrentPlayer() {
        return currentPlayer.getColour();
    }

    /**
     * The round number is determined by the number of moves MrX has played.
     * Initially this value is 0, and is incremented for each move MrX makes.
     * A double move counts as two moves.
     *
     * @return the number of moves MrX has played.
     */
    public int getRound() {
        return currentround;
    }

    /**
     * A list whose length-1 is the maximum number of moves that MrX can play in a game.
     * The getRounds().get(n) is true when MrX reveals the target location of move n,
     * and is false otherwise.
     * Thus, if getRounds().get(0) is true, then the starting location of MrX is revealed.
     *
     * @return a list of booleans that indicate the turns where MrX reveals himself.
     */
    public List<Boolean> getRounds() {
        return rounds;
    }

    private void increment(){
        currentround++;
        if(getRounds().get(currentround)) mrXlastknownlocation = players.get(0).getLocation();
    }

    public int getCurrentround(){
        return currentround;
    }
}
