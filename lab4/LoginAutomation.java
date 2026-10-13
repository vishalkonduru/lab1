import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;

public class LoginAutomation {
    public static void main(String[] args) {
        WebDriver driver = new ChromeDriver();

        try {
            driver.get("https://practicetestautomation.com/practice-test-login/");
            driver.manage().window().maximize();

            WebElement username = driver.findElement(By.id("username"));
            username.sendKeys("student");

            WebElement password = driver.findElement(By.id("password"));
            password.sendKeys("Password123");

            WebElement loginButton = driver.findElement(By.id("submit"));
            loginButton.click();

            WebElement message = driver.findElement(By.tagName("h1"));

            if (message.getText().equals("Logged In Successfully")) {
                System.out.println("Test Passed: Login Successful");
            } else {
                System.out.println("Test Failed: Login Not Successful");
            }

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            driver.quit();
        }
    }
}