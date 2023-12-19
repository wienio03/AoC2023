use std::fs;

fn main () {
    let file_path = "aoc2_input.txt";
    let file_content = fs::read_to_string(file_path)
                        .expect("readable file");
    print!("{file_content}");        
}