function getKeys(name)
    s = ""
    for k, v in pairs(_G[name]) do
        s = s..k..","
        end 
    return s
    end

Info = {
    arr = {1,2,4,5,6}
}