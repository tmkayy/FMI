package bg.sofia.uni.fmi.mjt.show;

import bg.sofia.uni.fmi.mjt.show.date.DateEvent;
import bg.sofia.uni.fmi.mjt.show.elimination.EliminationRule;
import bg.sofia.uni.fmi.mjt.show.ergenka.Ergenka;

public class ShowAPIImpl implements ShowAPI {

    private final Ergenka[] ergenkas;
    private final EliminationRule[] defaultEliminationRules;

    public ShowAPIImpl(Ergenka[] ergenkas, EliminationRule[] defaultEliminationRules) {
        this.ergenkas = ergenkas;
        this.defaultEliminationRules = defaultEliminationRules;
    }

    @Override
    public Ergenka[] getErgenkas() {
        return ergenkas;
    }

    @Override
    public void playRound(DateEvent dateEvent) {
        if (dateEvent == null)
            return;
        for (Ergenka ergenka : this.ergenkas) {
            organizeDate(ergenka, dateEvent);
        }
        eliminateErgenkas(defaultEliminationRules);
    }

    @Override
    public void eliminateErgenkas(EliminationRule[] eliminationRules) {
        if (eliminationRules == null || eliminationRules.length == 0) {
            for (EliminationRule er : defaultEliminationRules) {
                er.eliminateErgenkas(ergenkas);
            }
        } else {
            for (EliminationRule er : eliminationRules) {
                er.eliminateErgenkas(ergenkas);
            }
        }
    }

    @Override
    public void organizeDate(Ergenka ergenka, DateEvent dateEvent) {
        if (ergenka == null || dateEvent == null)
            return;
        ergenka.reactToDate(dateEvent);
    }
}
