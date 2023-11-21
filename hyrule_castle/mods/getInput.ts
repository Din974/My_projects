import * as readline from 'readline';

export const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

export function press_any_key() : Promise<string> {
    return new Promise((resolve) => {
      rl.question('\nPress any key to continue.\n', (userInput) => {
        resolve(userInput);
      });
    });
}