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

package com.fenbi.conan.aioralspam.server.util;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public abstract class ResourceFileReader {
  private final Logger LOG = LoggerFactory.getLogger(getClass());

  public boolean readResourceFile(String filePath) {
      BufferedReader reader = null;
      try {
          reader = new BufferedReader(new InputStreamReader(ResourceFileReader.class.getResourceAsStream(filePath)));
          String line;
          while ((line = reader.readLine()) != null) {
              processLine(line);
          }
          return true;
      } catch (Exception e) {
          LOG.error("read resource file error, path:" + filePath, e);
          return false;
      } finally {
          if (reader != null) {
              try {
                  reader.close();
              } catch (Exception e) {
                  LOG.error("exception ", e);
              }
          }
      }
  }

  public abstract void processLine(String line);
}

// 读取json文件
import org.apache.commons.io.FileUtils;
import com.fasterxml.jackson.core.type.TypeReference;
import com.fenbi.common.util.JsonUtils;

File file = new File("phones.json");
String content = FileUtils.readFileToString(file, "UTF-8");
List<Phone> phones = JsonUtils.readValue(content, new TypeReference<List<Phone>>(){});
