import React, {useState} from 'react';
import './styles/app.css'

const Words = () => {
    const [words, setWords]=useState([])
    const alphabet = ['а','б','в','г','д','е','ё','ж','з','и','й','к','л','м','н','о','п','р','с','т','у','ф','х','ц','ч','ш','щ','ы','э','ю','я']
    const [letters, setLetters] = useState(['т', 'с', 'е'])
    const[word,setWord]=useState('')
    const [isWordExist, setIsWordExist] = useState(false)
    const [isLoading, setIsLoading] = useState(false)
    const [game, setGame] = useState(true)
    const [wordRepeats, setWordRepeats] = useState(false)

    const [checkWord, setCheckWord] = useState(false)
    const [score, setScore] = useState(0)

    const clearWords=()=>{
        setWords([])
        setWord('')
        setLetters([])
    }

    function getRandomInt(max){
        return Math.floor(Math.random() * max);
    }

    const checkLetters = () =>{
        const wordLetters = word.toLowerCase().split('')
        const areLettersExist = letters.every((letter) => wordLetters.includes(letter))
        checkRepeat()
        setCheckWord(areLettersExist)
    }

    const checkRepeat = () =>{
        const isExist = words.includes(word.toLowerCase());
        setWordRepeats(isExist);
    }

    const addList = () =>{
        if (word !== ''){
            setWords([...words, word.toLowerCase()])
            setWord('')
            setScore(score + 10)
        }
    }

    const formSubmit = async (event) => {
        event.preventDefault()

        if(checkWord && game && !wordRepeats){
            setIsLoading(true)

            try {
                const response = await fetch(`https://dictionary.yandex.net/api/v1/dicservice.json/lookup?key=dict.1.1.20230516T152258Z.7ca86a7925d50b31.103d10cc5c380c6417a91e7dce6016267c31ea11&lang=ru-ru&text=${word}`)

                const data = await response.json()
                setIsWordExist(data.def.length > 0)
            } catch (error) {
                console.log(error)
            }

            setIsLoading(false)
            if(isWordExist) {
                addList()
                setScore(score + 10)
                setIsWordExist(false)
            }

        }
        else if(!checkWord || wordRepeats || (!isWordExist && !isLoading)){
            setGame(false)
            setWord('')

        }
    }

    const restart = () => {
        clearWords()
        const letter = []
        for(let i = 0; i < 3; i++)
        {
            letter[i] = alphabet[getRandomInt(31)]
        }
        setLetters([ letter[0], letter[1], letter[2]])
        setGame(true)
        setScore(0)
    }

    const giveUP = () =>{

    }


    return (
        <div className="App">
                <h1 className="Name">Гребешёк</h1>
            {!game && <p>Вы приграли, ваш счёт: {score}</p>}


            {
                letters.length ? (
                    <div>
                            Ваши буквы:
                            {
                                letters.map((el, id) => <p key={id}>"{el}"

                                </p>)
                            }

                    </div>
                ) : ''

            }



                <form onSubmit={formSubmit} className="Inputbox">
                    <input value ={word} className="input" onChange={e=> setWord(e.target.value)} type="text" id="txt" placeholder="Введите слово" required/>
                    <button onClick={checkLetters} type="submit" className="submit">Добавить</button>
                </form>



            {
                words.length ? (
                    <div>
                    <div className="Words">
                        {
                            words.map((el, id) => <div key={id}>{el}

                            </div>)
                        }
                    </div>

                    </div>
                ) : ''

            }
            <div onClick={restart} className="clearList" id="circ">Сдаться</div>
            <div onClick={restart} className="clearList" id="circ">Restart</div>



        </div>
    )
}

export default Words;