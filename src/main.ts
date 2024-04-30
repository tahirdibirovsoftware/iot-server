import { ReadlineParser, SerialPort } from "serialport";


const getDevicePath = async (deviceName: string)=>{

    const ports = await SerialPort.list()
    const arduinoPath = ports.filter(port=>port.manufacturer && port.manufacturer.toLowerCase().includes(deviceName.toLowerCase()))[0].path
    console.log(arduinoPath)
    return arduinoPath

}



const getPort = async ()=>{

    let path = await getDevicePath('arduino')


    const port = new SerialPort({
        baudRate: 115200,
        path: path
    }).setEncoding('utf-8')

    return port

}


const start = async ()=>{
    const port =  await getPort()

    const parser = port.pipe(new ReadlineParser())
    parser.on('data', console.log)
}


start()