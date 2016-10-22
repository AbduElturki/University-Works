package player;

import net.PlayerFactory;
import scotlandyard.Colour;
import scotlandyard.Player;
import scotlandyard.ScotlandYardView;
import scotlandyard.Spectator;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by abdu on 02/05/2016.
 */
public class MinMaxPlayerFactory implements PlayerFactory {
    @Override
    public Player getPlayer(Colour colour, ScotlandYardView view, String mapFilename) {
        return new MinMax(view, mapFilename);
    }

    @Override
    public void ready() {
    }

    @Override
    public List<Spectator> getSpectators(ScotlandYardView view) {
        ArrayList spectators = new ArrayList();
        return spectators;
    }

    @Override
    public void finish() {
    }
}
