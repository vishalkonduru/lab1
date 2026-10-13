import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.edge.EdgeDriver;

public class CrossBrowserLoginAutomation {
    public static void main(String[] args) {
        // List of browsers to test cross-browser compatibility
        String[] browsers = {"chrome", "edge"};

        for (String browser : browsers) {
            WebDriver driver = null;
            try {
                System.out.println("========================================");
                System.out.println("Running test on browser: " + browser.toUpperCase());
                System.out.println("========================================");

                // Initialize the corresponding browser driver
                if (browser.equalsIgnoreCase("chrome")) {
                    driver = new ChromeDriver();
                } else if (browser.equalsIgnoreCase("edge")) {
                    driver = new EdgeDriver();
                }

                if (driver != null) {
                    // Open login page
                    driver.get("https://practicetestautomation.com/practice-test-login/");
                    driver.manage().window().maximize();

                    // Enter credentials
                    WebElement username = driver.findElement(By.id("username"));
                    username.sendKeys("student");

                    WebElement password = driver.findElement(By.id("password"));
                    password.sendKeys("Password123");

                    // Click login
                    WebElement loginButton = driver.findElement(By.id("submit"));
                    loginButton.click();

                    // Verification
                    WebElement message = driver.findElement(By.tagName("h1"));

                    if (message.getText().equals("Logged In Successfully")) {
                        System.out.println("Test Passed: Login Successful on " + browser);
                    } else {
                        System.out.println("Test Failed: Login Not Successful on " + browser);
                    }
                }

            } catch (Exception e) {
                System.out.println("Error occurred on " + browser + ": " + e.getMessage());
            } finally {
                // Close browser after each test run
                if (driver != null) {
                    driver.quit();
                }
            }
            System.out.println("\n");
        }
    }
}