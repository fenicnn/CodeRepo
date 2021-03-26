// 常见语法
Collections.emptyList();
CollectionUtils.isEmpty();

// 文件读写
private List<Long> readData(String filename) {
        try {
            InputStream is = this.getClass().getResourceAsStream("/fix/" + filename);
            return JsonUtils.jsonToList(IOUtils.toString(is), new TypeReference<List<Long>>() {
            });
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

BufferedReader in = new BufferedReader(new FileReader("sensitive-word.csv"));
String str;
while ((str = in.readLine()) != null) {
  if(!SensitiveWordUtils.containsSensitiveWord(str)){
    System.out.println(String.format("Wrong: [%s]", str));
  }
}

7  package com.fenbi.conan.aioralspam.server.util;
8  
9  import org.slf4j.Logger;
10  import org.slf4j.LoggerFactory;
11  
12  import java.io.BufferedReader;
13  import java.io.InputStreamReader;
14  
18  public abstract class ResourceFileReader {
19      private final Logger LOG = LoggerFactory.getLogger(getClass());
20  
21      public boolean readResourceFile(String filePath) {
22          BufferedReader reader = null;
23          try {
24              reader = new BufferedReader(new InputStreamReader(ResourceFileReader.class.getResourceAsStream(filePath)));
25              String line;
26              while ((line = reader.readLine()) != null) {
27                  processLine(line);
28              }
29              return true;
30          } catch (Exception e) {
31              LOG.error("read resource file error, path:" + filePath, e);
32              return false;
33          } finally {
34              if (reader != null) {
35                  try {
36                      reader.close();
37                  } catch (Exception e) {
38                      LOG.error("exception ", e);
39                  }
40              }
41          }
42      }
43  
44      public abstract void processLine(String line);
45  }

// 读取json文件
import org.apache.commons.io.FileUtils;
import com.fasterxml.jackson.core.type.TypeReference;
import com.fenbi.common.util.JsonUtils;

File file = new File("phones.json");
String content = FileUtils.readFileToString(file, "UTF-8");
List<Phone> phones = JsonUtils.readValue(content, new TypeReference<List<Phone>>(){});
