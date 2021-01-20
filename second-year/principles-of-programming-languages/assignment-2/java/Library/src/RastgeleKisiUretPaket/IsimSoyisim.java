package RastgeleKisiUretPaket;

import java.io.File;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.List;

public class IsimSoyisim {
       
    public String olustur() throws IOException
    {
        int kisiDegeri = (int) ((System.currentTimeMillis() % 3001) +0);        
        Path filePath = new File("random_isimler.txt").toPath();
        Charset charset = Charset.defaultCharset();        
        List<String> stringList = Files.readAllLines(filePath, charset);
        String[] stringArray = stringList.toArray(new String[]{});
        return stringArray[kisiDegeri];    
    }
}