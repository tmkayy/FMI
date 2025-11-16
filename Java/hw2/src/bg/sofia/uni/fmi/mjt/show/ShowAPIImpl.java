package bg.sofia.uni.fmi.mjt.show;

import bg.sofia.uni.fmi.mjt.show.date.DateEvent;
import bg.sofia.uni.fmi.mjt.show.elimination.EliminationRule;
import bg.sofia.uni.fmi.mjt.show.elimination.LowestRatingEliminationRule;
import bg.sofia.uni.fmi.mjt.show.ergenka.Ergenka;

public class ShowAPIImpl implements ShowAPI {

    private Ergenka[] ergenkas;
    private final EliminationRule[] defaultEliminationRules;

    public ShowAPIImpl(Ergenka[] ergenkas, EliminationRule[] defaultEliminationRules) {
        this.ergenkas = ergenkas != null ? ergenkas : new Ergenka[0];

        if (defaultEliminationRules == null || defaultEliminationRules.length == 0) {
            this.defaultEliminationRules = new EliminationRule[]{new LowestRatingEliminationRule()};
        } else {
            this.defaultEliminationRules = defaultEliminationRules;
        }
    }

    @Override
    public Ergenka[] getErgenkas() {
        return ergenkas != null ? ergenkas : new Ergenka[0];
    }

    @Override
    public void playRound(DateEvent dateEvent) {
        DateEvent eventToUse = dateEvent;
        if (eventToUse == null) {
            eventToUse = new DateEvent("studio", 60, 5);
        }

        if (ergenkas == null) {
            ergenkas = new Ergenka[0];
            return;
        }

        for (Ergenka ergenka : this.ergenkas) {
            organizeDate(ergenka, eventToUse);
        }
        eliminateErgenkas(defaultEliminationRules);
    }

    @Override
    public void eliminateErgenkas(EliminationRule[] eliminationRules) {
        if (ergenkas == null) {
            ergenkas = new Ergenka[0];
            return;
        }
        EliminationRule[] rules = (eliminationRules == null || eliminationRules.length == 0) ? defaultEliminationRules : eliminationRules;

        for (EliminationRule rule : rules) {
            if (rule != null) {
                Ergenka[] result = rule.eliminateErgenkas(ergenkas);
                this.ergenkas = result != null ? result : new Ergenka[0];
            }
        }
    }

    @Override
    public void organizeDate(Ergenka ergenka, DateEvent dateEvent) {
        if (ergenka == null || dateEvent == null) {
            return;
        }
        ergenka.reactToDate(dateEvent);
    }
}