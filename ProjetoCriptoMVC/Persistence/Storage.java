package Persistence;

import Model.Cripto;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Storage {
    
    public boolean create(Cripto cripto) {
        try {
            FileWriter fileWriter = new FileWriter(cripto.getInitials() + ".txt");
            fileWriter.write(cripto.getName() + ";" + cripto.getInitials() + ";" + cripto.getRanking());
            fileWriter.close();
            return true;
        } catch (IOException e) {
            return false;
        }
    }

    public Cripto read(String symbol) {
        Cripto cripto = new Cripto();
        String content="";
        try {
            File file = new File(symbol + ".txt");
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
                content += scanner.nextLine();
            }
            scanner.close();
            String line[] = new String[3];
            line = content.split(";");
            cripto.setName(line[0]);
            cripto.setInitials(line[1]);          
            cripto.setRanking(Integer.parseInt(line[2]));
        } catch (IOException e) {
            System.out.println("Error");
        }
        return cripto;
    }
    
}
