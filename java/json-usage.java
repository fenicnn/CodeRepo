// 读取json文件
import org.apache.commons.io.FileUtils;
import com.fasterxml.jackson.core.type.TypeReference;
import com.fenbi.common.util.JsonUtils;

File file = new File("phones.json");
String content = FileUtils.readFileToString(file, "UTF-8");
List<Phone> phones = JsonUtils.readValue(content, new TypeReference<List<Phone>>(){});
